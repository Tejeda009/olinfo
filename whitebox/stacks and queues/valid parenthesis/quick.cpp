#include <bits/stdc++.h>

class Solution {
public:
    bool isValid(std::string& s) {
        if (s.size() % 2 != 0) return false;

        int top = -1; 

        for (char el : s) {
            switch (el) {
                case '(': s[++top] = ')'; break;
                case '[': s[++top] = ']'; break;
                case '{': s[++top] = '}'; break;
                default:
                    if (top == -1 || s[top] != el) {
                        return false;
                    }
                    --top; 
            }
        }

        return top == -1;
    }
};
