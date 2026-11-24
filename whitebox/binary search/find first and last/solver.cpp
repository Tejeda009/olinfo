#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline vector<int> searchRange(vector<int>& __restrict nums, const int target) noexcept {
        int n = static_cast<int>(nums.size());

        const int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (first == n || nums[first] != target) {
            return {-1, -1};
        }

        const int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {first, last};
    }
};


static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();