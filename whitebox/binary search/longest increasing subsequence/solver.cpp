#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline int lengthOfLIS(const vector<int>& __restrict_arr nums) noexcept {
        
        vector<int> sub;

        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); 
                *it = x; 
            }
        }

        return sub.size();
    }
};

static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();