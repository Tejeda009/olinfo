#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> students(N);

    for (int i = 0; i < N; i++) {
        cin >> students[i];
    }

    sort(students.begin(), students.end());

    for (int i = 0; i < Q; i++) {
        int curr;
        cin >> curr;

        const auto it = lower_bound(students.begin(), students.end(), curr);
        
        const int count = distance(it, students.end());

        cout << count << '\n';
    }

    return 0;
}