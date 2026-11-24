#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline int search(const vector<int>& __restrict nums, const int target) {
        int left = 0, right = static_cast<int>(nums.size());

        if (nums.size() == 1) return (nums[0] == target) ? 0 : -1;

        while(left <= right) {
            int middle = ((left + right) / 2);

            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return -1;
    }
};

static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();