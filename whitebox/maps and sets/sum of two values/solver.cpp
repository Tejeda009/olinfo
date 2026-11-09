#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    long long sum;
    cin >> size >> sum;

    map<long long, int> seen;

    for (int i = 0; i < size; i++) {
        long long val;
        cin >> val;

        long long complement = sum - val;

        if (seen.find(complement) != seen.end()) {
            cout << seen[complement] << " " << i + 1 << "\n";
            return 0;
        }

        seen[val] = i + 1;
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}