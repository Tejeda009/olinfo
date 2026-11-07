#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long Y;
    cin >> N >> Y;

    for (int x = 0; x <= N; ++x) {
        for (int y = 0; x + y <= N; ++y) {
            const int z = N - x - y; 
            
            if (10000LL * x + 5000LL * y + 1000LL * z == Y) {
                cout << x << " " << y << " " << z << "\n";
                return 0;
            }
        }
    }

    cout << "-1 -1 -1\n";
    return 0;
}