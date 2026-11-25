#include <bits/stdc++.h>
using namespace std;

class WindowJoiner {
    using Timestamp = long long;
    using Value = long long;

    using Bucket = deque<Value>;
    using TimeMap = map<Timestamp, Bucket>;
    using StreamsForKey = array<TimeMap, 2>;

    Timestamp window;
    Timestamp current_time = 0;
    bool has_current_time = false;

    unordered_map<string, StreamsForKey> buffers;
    map<Timestamp, set<pair<int, string>>> active_buckets;

    void remove_active(Timestamp t, int side, const string& key) {
        auto it = active_buckets.find(t);
        if (it == active_buckets.end()) return;

        it->second.erase({side, key});
        if (it->second.empty()) active_buckets.erase(it);
    }

    void evict_before(Timestamp cutoff) {
        while (!active_buckets.empty()) {
            auto it = active_buckets.begin();
            if (it->first >= cutoff) break;

            Timestamp t = it->first;
            auto buckets = std::move(it->second);
            active_buckets.erase(it);

            for (const auto& [side, key] : buckets) {
                auto kit = buffers.find(key);
                if (kit == buffers.end()) continue;

                kit->second[side].erase(t);

                if (kit->second[0].empty() && kit->second[1].empty())
                    buffers.erase(kit);
            }
        }
    }

    void push_event(int side, const string& key, Timestamp t, Value val) {
        if (!has_current_time) {
            current_time = t;
            has_current_time = true;
        } else {
            current_time = max(current_time, t);
        }

        const Timestamp cutoff = current_time - window;
        evict_before(cutoff);

        if (t < cutoff) {
            cout << "null\n";
            return;
        }

        const int other_side = side ^ 1;

        auto kit = buffers.find(key);
        TimeMap* other = nullptr;
        if (kit != buffers.end() && !kit->second[other_side].empty())
            other = &kit->second[other_side];

        if (other != nullptr) {
            bool found = false;
            Timestamp best_t = 0;
            Timestamp best_diff = numeric_limits<Timestamp>::max();

            auto lit = other->upper_bound(t);
            if (lit != other->begin()) {
                --lit;
                best_t = lit->first;
                best_diff = t - best_t;
                found = true;
            }

            auto rit = other->lower_bound(t);
            if (rit != other->end()) {
                Timestamp diff = rit->first - t;
                if (!found || diff < best_diff) {
                    best_t = rit->first;
                    best_diff = diff;
                    found = true;
                }
            }

            if (found && best_diff <= window) {
                auto bit = other->find(best_t);

                Value other_val = bit->second.front();
                bit->second.pop_front();

                if (bit->second.empty()) {
                    other->erase(bit);
                    remove_active(best_t, other_side, key);
                }

                if (kit->second[0].empty() && kit->second[1].empty())
                    buffers.erase(kit);

                if (side == 0) {
                    cout << key << ' ' << t << ' ' << val << ' '<< best_t << ' ' << other_val << '\n';
                } else {
                    cout << key << ' ' << best_t << ' ' << other_val << ' '<< t << ' ' << val << '\n';
                }
                return;
            }
        }

        auto& stream = buffers[key][side];
        auto [bit, inserted] = stream.try_emplace(t);
        bit->second.push_back(val);

        if (inserted)
            active_buckets[t].insert({side, key});

        cout << "null\n";
    }

public:
    explicit WindowJoiner(Timestamp w) : window(w) {}

    void push_a(const string& key, Timestamp t, Value a_val) {
        push_event(0, key, t, a_val);
    }

    void push_b(const string& key, Timestamp t, Value b_val) {
        push_event(1, key, t, b_val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string name;
    if (!(cin >> name) || name != "WindowJoiner") return 0;

    long long window;
    if (!(cin >> window)) return 0;

    WindowJoiner joiner(window);

    string command;
    while (cin >> command) {
        string key;
        long long t, val;
        if (!(cin >> key >> t >> val)) break;

        if (command == "push_a") {
            joiner.push_a(key, t, val);
        } else if (command == "push_b") {
            joiner.push_b(key, t, val);
        }
    }

    return 0;
}
