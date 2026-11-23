#include <bits/stdc++.h>
using namespace std;

class MysteriousMan {
    public:
        bool ask(int n) {
            return true;
        }

        void answer(int n) {

        }
};

constexpr int MAX_X = 10000000; 

static const std::bitset<MAX_X + 1>& get_primes() {
    static const std::bitset<MAX_X + 1> prime = []() {
        std::bitset<MAX_X + 1> p;
        p.set(); 
        p[0] = p[1] = false;

        for (int i = 2; i * i <= MAX_X; i++) {
            if (p[i]) {
                for (int j = i * i; j <= MAX_X; j += i) {
                    p[j] = false;
                }
            }
        }
        return p;
    }();
    return prime;
}


static inline void solve(MysteriousMan &man) {
    
    const auto& prime = get_primes();

    long long ans = 1;

    for (int p = 2; p <= MAX_X; p++) {
        if (prime[p]) {

            long long power = p;
            
            if (!man.ask(p)) {
                continue;
            }

            while (power * p <= MAX_X && man.ask(power * p)) {
                power *= p;
            }

            ans *= power;
        }
    }

    man.answer(ans);
}
