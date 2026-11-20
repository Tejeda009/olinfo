#include <bits/stdc++.h>

class Solution {
public:
    bool isValid(std::string s) {
        std::map<char, char> opener = {{')', '('}, {']', '['}, {'}', '{'}};
        std::stack<char> waiting;

        for (char el : s) {
            if (opener.count(el)) {
                if (waiting.empty() || waiting.top() != opener[el]) {
                    return false;
                }
                
                waiting.pop();
            } else {
                waiting.push(el);
            }
        }

        return waiting.empty();
    }
};