#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long size, curr, max = 0;
    cin >> size;

    unordered_set<long long> numbers;
    for (long long i = 0; i < size; i++) {
        cin >> curr;
        if (numbers.count(curr) == 1) {
            if (numbers.size() > max) max = numbers.size();
            numbers.clear();
            numbers.insert(curr);
        } else {
            numbers.insert(curr);
        }
    }

    if (numbers.size() > max) max = numbers.size();
    cout << max << '\n';

    return 0;
}