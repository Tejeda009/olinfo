#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long size;
    cin >> size;

    set<int> numbers;
    for (long long i = 0; i < size; i++) {
        int curr;
        cin >> curr;
        numbers.insert(curr);
    }

    cout << numbers.size() << '\n';
    return 0;
}