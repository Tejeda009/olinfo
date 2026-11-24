#include "returns/engine.hpp"

#include <algorithm>

namespace returns {

Engine::Engine(
    std::unordered_map<std::string, CategoryRule> category_map,
    std::vector<ScoringRule> scoring_rules,
    std::vector<DecisionBand> decision_bands,
    std::unordered_map<std::string, int> profile_map,
    std::unordered_map<std::string, std::unordered_set<std::string>> account_groups
)
    : category_map_(std::move(category_map))
    , scoring_rules_(std::move(scoring_rules))
    , decision_bands_(std::move(decision_bands))
    , profile_map_(std::move(profile_map))
    , account_groups_(std::move(account_groups))
{}

Engine Engine::build(
    const std::vector<CategoryRule>& category_rules,
    const std::vector<ScoringRule>& scoring_rules,
    const std::vector<DecisionBand>& decision_bands,
    const std::vector<AccountProfile>& profiles,
    const std::vector<AccountLink>& links
) {
    std::unordered_map<std::string, CategoryRule> category_map;
    for (const auto& rule : category_rules) {
        category_map[rule.category] = rule;
    }

    std::unordered_map<std::string, int> profile_map;
    for (const auto& profile : profiles) {
        profile_map[profile.account_id] = profile.return_history_count;
    }

    std::unordered_map<std::string, std::unordered_set<std::string>> account_groups;
    for (const auto& link : links) {
        if (link.primary_account_id == link.related_account_id) continue;
        account_groups[link.primary_account_id].insert(link.related_account_id);
        account_groups[link.related_account_id].insert(link.primary_account_id);
    }

    // Close each group transitively, so every member sees every other.
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto& [id, group] : account_groups) {
            std::unordered_set<std::string> expanded = group;
            for (const auto& member : group) {
                auto it = account_groups.find(member);
                if (it != account_groups.end()) {
                    for (const auto& transitive : it->second) {
                        if (transitive != id && expanded.find(transitive) == expanded.end()) {
                            expanded.insert(transitive);
                            changed = true;
                        }
                    }
                }
            }
            group = expanded;
        }
    }

    return Engine(
        std::move(category_map),
        scoring_rules,
        decision_bands,
        std::move(profile_map),
        std::move(account_groups)
    );
}

std::pair<std::string, std::string> Engine::check_category(const ReturnRequest& req) const {
    auto it = category_map_.find(req.category);
    if (it == category_map_.end()) {
        return {decision::REJECT, reason::CATEGORY_NON_RETURNABLE};
    }

    if (!it->second.returnable) {
        return {decision::REJECT, reason::CATEGORY_NON_RETURNABLE};
    }

    if (req.days_since_purchase > it->second.allowed_return_window_days) {
        return {decision::REJECT, reason::RETURN_WINDOW_EXPIRED};
    }

    return {"", ""};
}

int Engine::aggregate_return_history(const std::string& account_id) const {
    auto profile_it = profile_map_.find(account_id);
    int total = (profile_it != profile_map_.end()) ? profile_it->second : 0;

    auto group_it = account_groups_.find(account_id);
    if (group_it != account_groups_.end()) {
        for (const auto& linked_id : group_it->second) {
            auto linked_profile = profile_map_.find(linked_id);
            if (linked_profile != profile_map_.end()) {
                total += linked_profile->second;
            }
        }
    }

    return total;
}

int Engine::calculate_risk_score(const ReturnRequest& req, int total_return_history) const {
    int score = 0;

    for (const auto& rule : scoring_rules_) {
        int attribute_value = 0;
        if (rule.rule == rule_attr::TOTAL_RETURN_HISTORY) {
            attribute_value = total_return_history;
        } else if (rule.rule == rule_attr::ACCOUNT_AGE_DAYS) {
            attribute_value = req.account_age_days;
        } else if (rule.rule == rule_attr::ORDER_VALUE_USD) {
            attribute_value = req.order_value_usd;
        }

        int points = 0;
        for (const auto& range : rule.ranges) {
            if (attribute_value >= range.min && attribute_value <= range.max) {
                points = range.points;
            }
        }
        score += points;
    }

    return std::clamp(score, 0, 100);
}

std::pair<std::string, std::string> Engine::map_decision(int risk_score) const {
    for (const auto& band : decision_bands_) {
        if (risk_score >= band.min_score && risk_score <= band.max_score) {
            if (band.decision == decision::MANUAL_REVIEW) {
                return {band.decision, reason::MEDIUM_RISK_SCORE};
            }
            if (band.decision == decision::REJECT) {
                return {band.decision, reason::HIGH_RISK_SCORE};
            }
            return {band.decision, ""};
        }
    }
    return {decision::REJECT, reason::HIGH_RISK_SCORE};
}

std::vector<RoutingResult> Engine::evaluate(
    const std::vector<ReturnRequest>& requests
) const {
    std::vector<RoutingResult> results;
    results.reserve(requests.size());

    for (const auto& req : requests) {
        RoutingResult out;
        out.request_id = req.request_id;

        auto [cat_decision, cat_reason] = check_category(req);
        if (!cat_decision.empty()) {
            out.risk_score = std::nullopt;
            out.decision = cat_decision;
            out.reason = cat_reason;
            results.push_back(std::move(out));
            continue;
        }

        int total_history = aggregate_return_history(req.account_id);
        int risk_score = calculate_risk_score(req, total_history);

        auto [band_decision, band_reason] = map_decision(risk_score);
        out.risk_score = risk_score;
        out.decision = band_decision;
        out.reason = band_reason;
        results.push_back(std::move(out));
    }

    return results;
}

}  // namespace returns
