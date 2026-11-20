#include <bits/stdc++.h>
using namespace std;

static inline void printBuffer(const deque<string>& buf) {
    for (auto it = buf.rbegin(); it != buf.rend(); ++it) {
        if (it != buf.rbegin()) cout << " "; 
        cout << *it;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string in;
    cin >> in;
    if (in != "RingBuffer") return 0;

    short max;
    cin >> max;
    deque<string> buffer;
    string cmd = "";

    while(true) {
        cin >> cmd;
        if (cin.fail()) return 0;

        if (cmd == "snapshot") {
            printBuffer(buffer);
        } else if (cmd == "push") {
            string val;
            cin >> val;

            if (static_cast<short>(buffer.size()) >= max) {
                buffer.pop_back();
            } 

            buffer.push_front(val);

            cout << "null\n";
        }
    }

    return 0;
}