#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline bool searchMatrix(const vector<vector<int>>& __restrict matrix, const int target) {
        
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            const int mid = left + (right - left) / 2;
            const int val = matrix[mid / n][mid % n];

            if (val == target) {
                return true;
            }
            if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};


static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();