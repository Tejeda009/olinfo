#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> count(200, 0);

    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        int remainder = val % 200;
        count[remainder]++;
    }

    long long total_pairs = 0;
    for (int r = 0; r < 200; ++r) {
        if (count[r] >= 2) {
            total_pairs += count[r] * (count[r] - 1) / 2;
        }
    }

    cout << total_pairs << '\n';
    return 0;
}