#include <iostream>
#include <ostream>
#include <string>

#include "returns/engine.hpp"
#include "returns/file_io.hpp"

namespace returns {
namespace testing {

// Defined in tests/engine_test.cpp.
int run_named_test(const std::string& name, std::ostream& out);

}  // namespace testing
}  // namespace returns

namespace {

const char* const CATEGORY_RULES_PATH = "data/category_rules.json";
const char* const SCORING_RULES_PATH = "data/scoring_rules.json";
const char* const DECISION_BANDS_PATH = "data/decision_bands.json";
const char* const PROFILES_PATH = "data/account_profiles.jsonl";
const char* const LINKS_PATH = "data/account_links.jsonl";
const char* const RETURNS_PATH = "data/returns.jsonl";
const char* const RESULTS_PATH = "data/results.jsonl";

int run_pipeline() {
    auto category_rules = returns::read_category_rules(CATEGORY_RULES_PATH);
    auto scoring_rules = returns::read_scoring_rules(SCORING_RULES_PATH);
    auto decision_bands = returns::read_decision_bands(DECISION_BANDS_PATH);
    auto profiles = returns::read_account_profiles(PROFILES_PATH);
    auto links = returns::read_account_links(LINKS_PATH);
    auto requests = returns::read_return_requests(RETURNS_PATH);

    auto engine = returns::Engine::build(
        category_rules, scoring_rules, decision_bands, profiles, links
    );

    auto results = engine.evaluate(requests);
    returns::write_results(RESULTS_PATH, results);

    std::cout << "=== Running Return Routing Engine ===\n";
    std::cout << "Results written to: " << RESULTS_PATH << "\n";
    return 0;
}

std::string trim(const std::string& value) {
    const auto first = value.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    const auto last = value.find_last_not_of(" \t\r\n");
    return value.substr(first, last - first + 1);
}

}  // namespace

// One command on stdin: "run" routes data/returns.jsonl, anything else is a test name.
int main() {
    std::string command;
    std::getline(std::cin, command);
    command = trim(command);

    try {
        if (command.empty() || command == "run") {
            return run_pipeline();
        }
        return returns::testing::run_named_test(command, std::cout);
    } catch (const std::exception& error) {
        std::cerr << "error: " << error.what() << "\n";
        return 1;
    }
}
