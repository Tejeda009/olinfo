#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int ris;

    cin >> N;

        vector<int> num(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    for (int i = (int)num.size() - 1; i > 0; i--) {
        ris = num[i] + num[i-1];
        if (ris % 2 == 0) {
            cout << ris << endl;
            return 0;
        }

        if (i > 2) {
            ris = num[i] + num[i-2];
            if (ris % 2 == 0) {
                cout << ris << endl;
                return 0;
            }
        }
    }

    cout << "-1" << endl;

    return 0;
}