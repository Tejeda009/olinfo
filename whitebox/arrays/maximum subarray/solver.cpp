#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline int maxSubArray(const vector<int>& nums) {
        int ending_here = nums[0];
        int best = nums[0];

        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            ending_here = max(nums[i], ending_here + nums[i]);
            best = max(best, ending_here);
        }

        return best;
    }
};