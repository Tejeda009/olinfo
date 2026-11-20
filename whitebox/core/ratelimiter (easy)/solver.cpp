#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string in;
    if (!(cin >> in) || in != "RateLimiter") return 0;
    cout << "null\n";

    int cap, window, sum = 0;
    if (!(cin >> window >> cap)) return 0;

    map<int, int> additions;

    while (true) {
        string cmd;
        if (!(cin >> cmd)) return 0;
        if (cmd == "") return 0;

        if (cmd == "add") {
            int count, time;
            cin >> count >> time;

            auto it = additions.begin();
            while (it != additions.end() && it->first <= time - window) {
                sum -= it->second;
                it = additions.erase(it); 
            }

            int allowed = min(count, cap - sum);
            if (allowed > 0) {
                additions[time] += allowed;
                sum += allowed;
            }

            cout << "null\n";
        } else if (cmd == "check") {
            cout << sum << "\n";
        } else {
            cout << "Unknown command: " << cmd << "\n";
        }
    }
    return 0;
}
