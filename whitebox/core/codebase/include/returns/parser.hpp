#pragma once

#include <string>
#include <vector>

#include "returns/models.hpp"

namespace returns {

std::vector<CategoryRule> parse_category_rules_json(const std::string& json);
std::vector<ScoringRule> parse_scoring_rules_json(const std::string& json);
std::vector<DecisionBand> parse_decision_bands_json(const std::string& json);

AccountProfile parse_account_profile_line(const std::string& line);
AccountLink parse_account_link_line(const std::string& line);
ReturnRequest parse_return_request_line(const std::string& line);

}  // namespace returns
