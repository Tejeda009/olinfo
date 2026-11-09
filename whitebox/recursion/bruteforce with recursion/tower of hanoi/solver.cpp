#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    1 1
    2 3
    3
    5
    4
    */

    int disks;
    vector<pair<int, int>> moves;
    cin >> disks;

    if (disks == 1) {
        cout << "1\n1 3\n";
        return 0;
    } else if (disks == 2) {
        cout << "3\n1 2\n1 3\n2 3\n";
        return 0;
    }

    cout << (disks * 2) + 1 << '\n';

    int copydisks = disks;
    while(copydisks > 1) {
        cout << "1 2\n"; 
        copydisks--;
    }

    cout << "1 3\n";

    while (disks > 1) {
        disks--;
        cout << "2 3\n";
    }

    return 0;
}