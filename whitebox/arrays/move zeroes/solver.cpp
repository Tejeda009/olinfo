#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline void moveZeroes(vector<int>& nums) {
        int write = 0;

        for (const int el : nums) {
            if (el != 0) {
                nums[write] = el;
                write++;
            }
        }

        for (int i = write; i < static_cast<int>(nums.size()); i++) {
            nums[i] = 0;
        }
    }
};