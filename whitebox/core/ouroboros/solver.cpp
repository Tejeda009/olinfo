#include <bits/stdc++.h>
using namespace std;

/**
 * @param n The size of the array
 * @param k The step size
 * @param a The array input
 */
void solve(int n, int k, vector<int> &a) {
    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        nums[i] = a[i] + a[(i + k) % n];
    }

    for (int i = 0; i < n; i++) {
        a[i] = nums[i];
    } 
   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (auto& in : nums) {
        cin >> in;
    }

    solve(n, k, nums);

    return 0;
}