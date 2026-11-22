#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline void reverseString(vector<char>& __restrict s) noexcept {
        reverse(s.begin(), s.end());
    }
};

static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; // Opzionale, vedi nota sotto
    return 0;
}();
