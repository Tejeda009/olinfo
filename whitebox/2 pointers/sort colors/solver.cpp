#include <bits/stdc++.h>
#include <vector>
//leetcode
/*You are given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    int app = nums[i];
                    nums[i] = nums[j];
                    nums[j] = app;
                }
            }
        }
    }
};