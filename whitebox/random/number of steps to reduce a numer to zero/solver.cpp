#include <bit>
using namespace std;

class Solution {
public:

    static inline int numberOfSteps(int num) {
        if (num == 0) return 0;

        return std::bit_width(static_cast<unsigned int>(num)) + std::popcount(static_cast<unsigned int>(num)) - 1;
    }

};
