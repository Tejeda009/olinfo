#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline int searchInsert(const vector<int>& __restrict nums, const int target) noexcept {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();