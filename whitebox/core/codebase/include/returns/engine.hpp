#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "returns/models.hpp"

namespace returns {

// Category checks, then risk score, then decision and reason.
class Engine {
public:
    Engine(
        std::unordered_map<std::string, CategoryRule> category_map,
        std::vector<ScoringRule> scoring_rules,
        std::vector<DecisionBand> decision_bands,
        std::unordered_map<std::string, int> profile_map,
        std::unordered_map<std::string, std::unordered_set<std::string>> account_groups
    );

    static Engine build(
        const std::vector<CategoryRule>& category_rules,
        const std::vector<ScoringRule>& scoring_rules,
        const std::vector<DecisionBand>& decision_bands,
        const std::vector<AccountProfile>& profiles,
        const std::vector<AccountLink>& links
    );

    // Returns {decision, reason}, or {"", ""} when the request passes.
    std::pair<std::string, std::string> check_category(const ReturnRequest& req) const;

    // Own history plus every linked account's, transitively.
    int aggregate_return_history(const std::string& account_id) const;

    // Sum of the rule points, clamped to 0-100.
    int calculate_risk_score(const ReturnRequest& req, int total_return_history) const;

    std::pair<std::string, std::string> map_decision(int risk_score) const;

    // Results come back in request order.
    std::vector<RoutingResult> evaluate(const std::vector<ReturnRequest>& requests) const;

private:
    std::unordered_map<std::string, CategoryRule> category_map_;
    std::vector<ScoringRule> scoring_rules_;
    std::vector<DecisionBand> decision_bands_;
    std::unordered_map<std::string, int> profile_map_;
    std::unordered_map<std::string, std::unordered_set<std::string>> account_groups_;
};

}  // namespace returns
