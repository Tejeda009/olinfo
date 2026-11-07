#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string cmd;
    const string snap = "snapshot";
    const string push = "push";
    long long size;
    vector<int> numbers;
    int num, cont = 0;

    cin >> cmd;
    if (cmd != "RingBuffer") return;
    cin >> num;

    numbers.reserve(num);
    cout << "null" << '\n';

    cin >> cmd;
    if (cmd == push) {
        cin >> num;
        cont++;
        if (cont > size) numbers.erase(0);
        numbers.insert(num);
        cout << "null" << '\n';
    } else if (cmd == snap) {
        for (const int curr: numbers) {
            cout << curr << " ";
        }
    } else {
        cout << "error" << '\n';
    }

    return 0;
}