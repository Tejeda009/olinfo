#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, size;
    cin >> n >> size;

    n = static_cast<size_t>(n);
    vector<int> thickness(n);
    vector<int> lenghts(n);

    for(size_t i = 0; i < n; i++) {
        cin >> thickness[i];
        cin >> lenghts[i];
    }

    for (size_t i = 0; i < size; i++) {

        int max = (lenghts[0] + 1) * thickness[0];

        for (size_t j = 0; j < n; j++) {

            lenghts[j] += 1;
            max = std::max(max, lenghts[j] * thickness[j]);
        }

        cout << max << "\n";
    }

    return 0;
}