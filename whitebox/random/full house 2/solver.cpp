#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, int> nums;
    for(uint8_t i = (uint8_t) 0; i < (uint8_t) 4; i++) {
        int curr;
        cin >> curr;

        nums[curr]++;
    }

    if (nums.size() == 2) {
        cout << "Yes\n";
        return 0;
    }

    bool flag = false;

    for (const auto& [key, value] : nums) {

        if (value == 2 || value == 3) {

            if (flag) {
                cout << "Yes\n";
                return 0;
            }

            flag = true;
        }
    }

    cout << "No\n";

    return 0;
}