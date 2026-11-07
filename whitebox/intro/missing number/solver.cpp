#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long size, sum = 0;
    cin >> size;

    for (long long i = 0; i < size - 1; i++) {
        long long curr;
        cin >> curr;
        sum += curr;
    }

    const long long realsum = (size * (size + 1)) / 2;
    const long long ret = realsum - sum;

    cout << ret << '\n';

    return 0;
}