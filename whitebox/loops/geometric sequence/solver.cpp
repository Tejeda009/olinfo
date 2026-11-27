#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> nums(n);

    for (auto& el : nums) {
        cin >> el;
    }

    for (auto el : nums) {
        if (el == 0) {
            cout << "No\n";
            return 0;
        }
    }

    if (n <= 2) {
        cout << "Yes\n";
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        if ((__int128)nums[i + 1] * nums[0] != (__int128)nums[i] * nums[1]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}