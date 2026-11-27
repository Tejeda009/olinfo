#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline int maxOperations(vector<int>& __restrict_arr nums) noexcept {
        
        int score = nums[0] + nums[1], count = 1;
        for (int i = 2; i + 1 < nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] == score) count++;
            else break;
        }
        return count;

    }
};

static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();