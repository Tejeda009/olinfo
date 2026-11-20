#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline int findMaxConsecutiveOnes(const vector<int>& nums) {
        int cont = 0;
        int massimo = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] == 1) {
                cont++;
                massimo = max(massimo, cont);
            } else {
                cont = 0;
            }
        }

        return massimo;
    }
};