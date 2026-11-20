#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size, number, level, sum = 0;
    cin >> size >> number >> level;

    vector<vector<int>> data (size, vector<int>(number));
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < number; j++ ) {
            cin >> data[i][j];
        }
    }

    for (int i = 1; i < number; i++) {
        for (int j = 0; j < size; j++) {
            cout << data[j][i] << " ";
            sum += data[j][i];
        }

        cout << "\n";

        if (sum < level) {
            cout << "-1\n";
            return 0;
        }
    }

    return 0;
}