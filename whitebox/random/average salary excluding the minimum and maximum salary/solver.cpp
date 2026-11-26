#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    static inline double average(const vector<int>& __restrict salary) noexcept {
        int sum = 0;

        int max = salary[0], min = max;
        for (const int& el : salary) {

            max = std::max(max, el);
            min = std::min(min, el);

            sum += el;
        }

        sum -= min + max;

        return static_cast<double>(sum) / (salary.size() - 2);
    }
};


static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();