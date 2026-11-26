#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

static int binpow(long long a, long long b) noexcept {
    long long res = 1;
    a %= MOD;

    if (a < 0) a += MOD;

    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }
    return static_cast<int>(res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        long long a, b;
        cin >> a >> b;
        
        cout << binpow(a, b) << "\n";
    }

    return 0;
}