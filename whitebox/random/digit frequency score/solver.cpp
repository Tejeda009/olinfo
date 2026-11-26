#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline int digitFrequencyScore(int n) noexcept {
        string str = to_string(n);
        unordered_map<int, int> freq (str.size());

        int sum = 0;

        for (const auto& el : str) {
            int num = el - '0';

            freq[num]++;
        }

        for (const auto& [key, value] : freq) {
            sum += key * value;
        }
        
        return sum;
    }
};


static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();