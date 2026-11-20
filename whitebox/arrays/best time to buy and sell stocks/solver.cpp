#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int lowest = prices[0];
        int best = 0;

        for (const int price : prices) {
            best = max(best, price - lowest);
            lowest = min(lowest, price);
        }

        return best;
    }
};