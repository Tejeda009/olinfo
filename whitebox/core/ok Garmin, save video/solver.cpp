#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    {
        string in;
        cin >> in;
        if (in != "Replayer") return 0;
    }

    int start_seq, max_buffer;
    cin >> start_seq >> max_buffer;

    map<int, string> values;

    while(true) {

        {
            string in;
            if(!(cin >> in) || in != "push") return 0;
        }

        if (static_cast<int> (values.size()) > max_buffer) {
            cout << "error\n";
            return 0;
        }

        int seq;
        string payload;
        cin >> seq >> payload;

        if (seq < start_seq || values.count(seq)) {
            cout << "null\n";
            continue;
        }

        values[seq] = payload;

        if (static_cast<int>(values.size()) > max_buffer) {
            cout << "error\n";
            return 0;
        }

        if (values.begin()->first != start_seq) {
            cout << "null\n";
        } else {
            bool first = true;

            while(!values.empty() && values.begin()->first == start_seq) {
                if (!first) cout << " ";

                cout << values.begin()->second;
                first = false;

                values.erase(values.begin());
                start_seq++;
            }

            cout << '\n';
        }



    }


    return 0;
}