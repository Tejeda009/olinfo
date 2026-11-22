#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    inline vector<int> runningSum(vector<int>& nums) const {
        std::vector<int> sum(nums.size());

        sum[0] = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i];
        }

        return sum;
    }
};

int main() {
    std::vector<int> test = {1, 1, 1, 1, 1};

    Solution sol;
    std::vector<int> arr = sol.runningSum(test);

    for (const auto& el : arr) {
        cout << el << " ";
    }

    return 0;
}