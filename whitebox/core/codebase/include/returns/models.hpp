#pragma once

#include <optional>
#include <string>
#include <vector>

namespace returns {

struct CategoryRule {
    std::string category;
    bool returnable = false;
    // Largest days_since_purchase still inside the window.
    int allowed_return_window_days = 0;
};

struct ScoreRange {
    int min = 0;
    int max = 0;
    int points = 0;
};

struct ScoringRule {
    std::string rule;
    std::vector<ScoreRange> ranges;
};

// Both ends inclusive.
struct DecisionBand {
    int min_score = 0;
    int max_score = 0;
    std::string decision;
};

struct AccountProfile {
    std::string account_id;
    int return_history_count = 0;
};

struct AccountLink {
    std::string primary_account_id;
    std::string related_account_id;
    std::string link_type;
};

struct ReturnRequest {
    std::string request_id;
    std::string account_id;
    std::string category;
    int days_since_purchase = 0;
    // Both default to 0 when the request line leaves them out.
    int order_value_usd = 0;
    int account_age_days = 0;
};

// risk_score stays empty for a request that never reached scoring,
// reason for one that was approved.
struct RoutingResult {
    std::string request_id;
    std::optional<int> risk_score;
    std::string decision;
    std::string reason;
};

namespace decision {
inline constexpr const char* AUTO_APPROVE = "AUTO_APPROVE";
inline constexpr const char* MANUAL_REVIEW = "MANUAL_REVIEW";
inline constexpr const char* REJECT = "REJECT";
}  // namespace decision

namespace reason {
inline constexpr const char* CATEGORY_NON_RETURNABLE = "CATEGORY_NON_RETURNABLE";
inline constexpr const char* RETURN_WINDOW_EXPIRED = "RETURN_WINDOW_EXPIRED";
inline constexpr const char* MEDIUM_RISK_SCORE = "MEDIUM_RISK_SCORE";
inline constexpr const char* HIGH_RISK_SCORE = "HIGH_RISK_SCORE";
}  // namespace reason

namespace rule_attr {
inline constexpr const char* TOTAL_RETURN_HISTORY = "total_return_history";
inline constexpr const char* ACCOUNT_AGE_DAYS = "account_age_days";
inline constexpr const char* ORDER_VALUE_USD = "order_value_usd";
}  // namespace rule_attr

}  // namespace returns
