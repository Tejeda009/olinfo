#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long size;
    cin >> size;

    set<long long> numbers;
    for (long long i = 0; i < size; i++) {
        long long curr;
        cin >> curr;
        numbers.insert(curr);
    }

    cout << numbers.size() << '\n';
    return 0;
}