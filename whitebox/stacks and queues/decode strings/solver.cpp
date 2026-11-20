#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string_view s) {
        stack<pair<string, int>> saved;  
        string current;
        int count = 0;
        for (char ch : s) {
            if (isdigit(ch)) {
                count = count * 10 + (ch - '0');
            } else if (ch == '[') {
                saved.push({current, count});
                current = "";
                count = 0;
            } else if (ch == ']') {
                auto [before, times] = saved.top();
                saved.pop();
                string repeated;
                for (int i = 0; i < times; i++) {
                    repeated += current;
                }
                current = before + repeated;
            } else {
                current += ch;
            }
        }

        return current;
    }
};