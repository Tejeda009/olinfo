#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline int maxDigitRange(const vector<int>& nums) {
        int max = 0;
        int sum = 0;

        for(const auto& el : nums) {
            const string test = to_string(el);

            const int digit = getDigitRange(test);
            max = std::max(max, digit);
        }

        for (const auto& el : nums) {
            const string test = to_string(el);

            const int digit = getDigitRange(test);

            if (digit == max) {
                sum += el;
            }
        }

        return sum;
    }

    static int getDigitRange(string_view in) {
        int char_max = 0, min = INT_MAX;

        for (auto cha : in) {
            cha -= '0';

            char_max = std::max(char_max, static_cast<int>(cha));
            min = std::min(min, static_cast<int>(cha));
        }

        return (char_max - min);
    }
};

static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();

int main() {
    Solution sol;

    cout << sol.getDigitRange("5724"); 
}