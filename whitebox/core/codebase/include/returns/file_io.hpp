#pragma once

#include <string>
#include <vector>

#include "returns/models.hpp"

namespace returns {

std::vector<CategoryRule> read_category_rules(const std::string& path);
std::vector<ScoringRule> read_scoring_rules(const std::string& path);
std::vector<DecisionBand> read_decision_bands(const std::string& path);
std::vector<AccountProfile> read_account_profiles(const std::string& path);
std::vector<AccountLink> read_account_links(const std::string& path);
std::vector<ReturnRequest> read_return_requests(const std::string& path);

/// Write one JSON object per result, in the order given.
void write_results(const std::string& path, const std::vector<RoutingResult>& results);

}  // namespace returns
