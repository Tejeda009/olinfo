#include <bits/stdc++.h>
using namespace std;

class Window {

public:

    int size;
    int current_time = 0;
    std::vector<tuple<string, int, int>> stream_a;
    std::vector<tuple<string, int, int>> stream_b;

    Window(const int size) : size(size) {};


    std::vector<int> push_a(string_view key, const int time, const int val) {
        std::vector<int> result;

        if (time < current_time - size) {
            return vector<int> (1, 1);
        }

        current_time = max(current_time, time);

        for (auto& [k, t, value] : stream_b) {
            if (k == key) {
                result.push_back([k, t, value]);
            }
        }

    }

    std::vector<int> push_b(string_view key, const int time, const int val) {
        if (time < current_time - size) {
            return vector<int> (1, 1);
        }

        current_time = max(current_time, time);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}