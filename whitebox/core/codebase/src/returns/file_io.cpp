#include "returns/file_io.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "returns/parser.hpp"

namespace returns {

namespace {

std::string read_whole_file(const std::string& path) {
    std::ifstream in(path);
    if (!in) throw std::runtime_error("cannot open " + path);
    std::ostringstream buffer;
    buffer << in.rdbuf();
    return buffer.str();
}

bool is_blank(const std::string& line) {
    return line.find_first_not_of(" \t\r\n") == std::string::npos;
}

template <typename T, typename Parse>
std::vector<T> read_jsonl(const std::string& path, Parse parse) {
    std::vector<T> out;
    std::ifstream in(path);
    if (!in) throw std::runtime_error("cannot open " + path);
    std::string line;
    while (std::getline(in, line)) {
        if (is_blank(line)) continue;
        out.push_back(parse(line));
    }
    return out;
}

}  // namespace

std::vector<CategoryRule> read_category_rules(const std::string& path) {
    return parse_category_rules_json(read_whole_file(path));
}

std::vector<ScoringRule> read_scoring_rules(const std::string& path) {
    return parse_scoring_rules_json(read_whole_file(path));
}

std::vector<DecisionBand> read_decision_bands(const std::string& path) {
    return parse_decision_bands_json(read_whole_file(path));
}

std::vector<AccountProfile> read_account_profiles(const std::string& path) {
    return read_jsonl<AccountProfile>(path, parse_account_profile_line);
}

std::vector<AccountLink> read_account_links(const std::string& path) {
    return read_jsonl<AccountLink>(path, parse_account_link_line);
}

std::vector<ReturnRequest> read_return_requests(const std::string& path) {
    return read_jsonl<ReturnRequest>(path, parse_return_request_line);
}

void write_results(const std::string& path, const std::vector<RoutingResult>& results) {
    std::ofstream out(path);
    if (!out) throw std::runtime_error("cannot write " + path);
    for (const auto& result : results) {
        out << "{\"request_id\":\"" << result.request_id << "\",\"risk_score\":";
        if (result.risk_score.has_value()) {
            out << result.risk_score.value();
        } else {
            out << "null";
        }
        out << ",\"decision\":\"" << result.decision << "\"";
        if (!result.reason.empty()) {
            out << ",\"reason\":\"" << result.reason << "\"";
        }
        out << "}\n";
    }
}

}  // namespace returns
