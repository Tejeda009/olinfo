#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline vector<int> twoSum(vector<int>& __restrict nums, int target) {
        unordered_map<long long, int> first;
        const int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long need = 1LL * target - nums[i];
            if (first.count(need)) {
                return {first[need], i};
            }
            if (!first.count(nums[i])) {
                first[nums[i]] = i;
            }
        }
        
        return {};
    }
};

static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();

int main() {
    std::vector<int> test = {2, 7, 11, 15};
    Solution sol;
    sol.twoSum(test, 9);
}