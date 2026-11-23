#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline bool isThree(int n) {

        short cont = 0;
        for(short i = 1; i <= static_cast<short>(n); i++) {
            if (n % i == 0) {
                cont++;
            }
        }

        return cont == 3;
        
    }
};

static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; 
    return 0;
}();