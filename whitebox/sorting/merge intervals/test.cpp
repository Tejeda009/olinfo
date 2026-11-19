#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> out (intervals.size(), vector<int>(2));
    set<int> test;
    int idx = 0;
    short thi = 0;

    for (int i = 0; i < intervals.size(); i++) {
        test.insert(intervals[i][0]);
        test.insert(intervals[i][1]);
    }

    for (const int el : test) {
        if (thi == 2) {
            thi = 0;
            idx++;
        }

        out[idx][thi] = el;
        thi++;
    }

    cout << "Dati: \n";
    for (int i = 0; i < out.size(); i++) {
        cout << out[i][0] << " " << out[i][1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}