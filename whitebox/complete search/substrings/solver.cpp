#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = static_cast<int>(s.size());
    int m = static_cast<int>(t.size());
    int max_match = 0;

    for (int i = 0; i <= n - m; i++) {
        int current_match = 0;
        
        for (int j = 0; j < m; j++) {
            if (s[i + j] == t[j]) {
                current_match++;
            }
        }
        
        max_match = max(max_match, current_match);
    }

    cout << m - max_match << "\n";

    return 0;
}
