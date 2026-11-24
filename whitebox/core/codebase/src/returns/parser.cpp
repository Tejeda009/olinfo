#include "returns/parser.hpp"

#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>

namespace returns {

namespace {

// Enough JSON for the config documents and the JSONL records, and no more.
class JsonParser {
public:
    explicit JsonParser(const std::string& json) : json_(json), pos_(0) {}

    std::vector<CategoryRule> parse_category_rules_document() {
        std::vector<CategoryRule> rules;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "category_rules") {
                expect('[');
                skip_ws();
                if (peek() == ']') {
                    pos_++;
                } else {
                    while (true) {
                        rules.push_back(parse_category_rule_object());
                        skip_ws();
                        if (peek() == ']') { pos_++; break; }
                        expect(',');
                        skip_ws();
                    }
                }
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return rules;
    }

    std::vector<ScoringRule> parse_scoring_rules_document() {
        std::vector<ScoringRule> rules;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "scoring_rules") {
                expect('[');
                skip_ws();
                if (peek() == ']') {
                    pos_++;
                } else {
                    while (true) {
                        rules.push_back(parse_scoring_rule_object());
                        skip_ws();
                        if (peek() == ']') { pos_++; break; }
                        expect(',');
                        skip_ws();
                    }
                }
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return rules;
    }

    std::vector<DecisionBand> parse_decision_bands_document() {
        std::vector<DecisionBand> bands;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "decision_bands") {
                expect('[');
                skip_ws();
                if (peek() == ']') {
                    pos_++;
                } else {
                    while (true) {
                        bands.push_back(parse_decision_band_object());
                        skip_ws();
                        if (peek() == ']') { pos_++; break; }
                        expect(',');
                        skip_ws();
                    }
                }
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return bands;
    }

    AccountProfile parse_account_profile_object() {
        AccountProfile p;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "account_id") {
                p.account_id = parse_string();
            } else if (key == "return_history_count") {
                p.return_history_count = parse_int();
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return p;
    }

    AccountLink parse_account_link_object() {
        AccountLink link;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "primary_account_id") {
                link.primary_account_id = parse_string();
            } else if (key == "related_account_id") {
                link.related_account_id = parse_string();
            } else if (key == "link_type") {
                link.link_type = parse_string();
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return link;
    }

    ReturnRequest parse_return_request_object() {
        ReturnRequest r;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "request_id") {
                r.request_id = parse_string();
            } else if (key == "account_id") {
                r.account_id = parse_string();
            } else if (key == "category") {
                r.category = parse_string();
            } else if (key == "days_since_purchase") {
                r.days_since_purchase = parse_int();
            } else if (key == "order_value_usd") {
                r.order_value_usd = parse_int();
            } else if (key == "account_age_days") {
                r.account_age_days = parse_int();
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return r;
    }

private:
    CategoryRule parse_category_rule_object() {
        CategoryRule rule;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "category") {
                rule.category = parse_string();
            } else if (key == "returnable") {
                rule.returnable = parse_bool();
            } else if (key == "allowed_return_window_days") {
                rule.allowed_return_window_days = parse_int();
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return rule;
    }

    ScoringRule parse_scoring_rule_object() {
        ScoringRule rule;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "rule") {
                rule.rule = parse_string();
            } else if (key == "ranges") {
                expect('[');
                skip_ws();
                if (peek() == ']') {
                    pos_++;
                } else {
                    while (true) {
                        rule.ranges.push_back(parse_score_range_object());
                        skip_ws();
                        if (peek() == ']') { pos_++; break; }
                        expect(',');
                        skip_ws();
                    }
                }
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return rule;
    }

    ScoreRange parse_score_range_object() {
        ScoreRange range;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "min") {
                range.min = parse_int();
            } else if (key == "max") {
                range.max = parse_int();
            } else if (key == "points") {
                range.points = parse_int();
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return range;
    }

    DecisionBand parse_decision_band_object() {
        DecisionBand band;
        skip_ws();
        expect('{');
        while (true) {
            skip_ws();
            if (peek() == '}') { pos_++; break; }

            std::string key = parse_string();
            skip_ws();
            expect(':');
            skip_ws();

            if (key == "min_score") {
                band.min_score = parse_int();
            } else if (key == "max_score") {
                band.max_score = parse_int();
            } else if (key == "decision") {
                band.decision = parse_string();
            } else {
                skip_value();
            }

            skip_ws();
            if (peek() == ',') pos_++;
        }
        return band;
    }

    void skip_ws() {
        while (pos_ < json_.size() && std::isspace(static_cast<unsigned char>(json_[pos_]))) {
            pos_++;
        }
    }

    char peek() const {
        return pos_ < json_.size() ? json_[pos_] : '\0';
    }

    void expect(char c) {
        if (pos_ >= json_.size() || json_[pos_] != c) {
            throw std::runtime_error(std::string("expected '") + c + "' in JSON input");
        }
        pos_++;
    }

    std::string parse_string() {
        skip_ws();
        expect('"');
        std::string out;
        while (pos_ < json_.size() && json_[pos_] != '"') {
            if (json_[pos_] == '\\' && pos_ + 1 < json_.size()) {
                out.push_back(json_[pos_ + 1]);
                pos_ += 2;
                continue;
            }
            out.push_back(json_[pos_]);
            pos_++;
        }
        expect('"');
        return out;
    }

    int parse_int() {
        int start = static_cast<int>(pos_);
        if (peek() == '-') pos_++;
        while (pos_ < json_.size() && std::isdigit(static_cast<unsigned char>(json_[pos_]))) {
            pos_++;
        }
        return std::atoi(json_.substr(start, pos_ - start).c_str());
    }

    bool parse_bool() {
        if (peek() == 't') {
            pos_ += 4;
            return true;
        }
        pos_ += 5;
        return false;
    }

    // Consumes a value of any type without storing it.
    void skip_value() {
        skip_ws();
        char c = peek();
        if (c == '"') {
            parse_string();
            return;
        }
        if (c == '{' || c == '[') {
            int depth = 0;
            while (pos_ < json_.size()) {
                char d = json_[pos_];
                if (d == '"') {
                    parse_string();
                    continue;
                }
                if (d == '{' || d == '[') {
                    depth++;
                } else if (d == '}' || d == ']') {
                    depth--;
                    if (depth == 0) {
                        pos_++;
                        return;
                    }
                }
                pos_++;
            }
            return;
        }
        while (pos_ < json_.size() && json_[pos_] != ',' && json_[pos_] != '}' && json_[pos_] != ']') {
            pos_++;
        }
    }

    const std::string& json_;
    std::size_t pos_;
};

}  // namespace

std::vector<CategoryRule> parse_category_rules_json(const std::string& json) {
    JsonParser parser(json);
    return parser.parse_category_rules_document();
}

std::vector<ScoringRule> parse_scoring_rules_json(const std::string& json) {
    JsonParser parser(json);
    return parser.parse_scoring_rules_document();
}

std::vector<DecisionBand> parse_decision_bands_json(const std::string& json) {
    JsonParser parser(json);
    return parser.parse_decision_bands_document();
}

AccountProfile parse_account_profile_line(const std::string& line) {
    JsonParser parser(line);
    return parser.parse_account_profile_object();
}

AccountLink parse_account_link_line(const std::string& line) {
    JsonParser parser(line);
    return parser.parse_account_link_object();
}

ReturnRequest parse_return_request_line(const std::string& line) {
    JsonParser parser(line);
    return parser.parse_return_request_object();
}

}  // namespace returns
