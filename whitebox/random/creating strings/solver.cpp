#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    sort(n.begin(), n.end());

    vector<string> permutations;
    do {
        permutations.push_back(n);
    } while (next_permutation(n.begin(), n.end()));

    cout << permutations.size() << "\n";
    for (const string& p : permutations) {
        cout << p << "\n";
    }
    return 0;
}