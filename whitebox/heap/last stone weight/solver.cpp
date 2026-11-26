#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline int lastStoneWeight(vector<int>& __restrict_arr stones) noexcept {
        priority_queue<int> stack(begin(stones), end(stones));
    

        while(stack.size() > 1) {
            const int x = stack.top();
            stack.pop();
            const int y = stack.top();
            stack.pop();

            if (x > y) stack.push(x - y);
        }

        return (stack.empty()) ? 0 : stack.top();
    }
};