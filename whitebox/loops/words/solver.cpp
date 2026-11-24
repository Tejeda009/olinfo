#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string in;
    cin >> in;

    int contl = 0, contu = 0;
    for (const auto& cha: in) {
        if (isupper(cha)) contu++;
        else contl++;
    }

    string out;
    for (const auto& cha : in) {
        out += (contl >= contu) ? tolower(cha) : toupper(cha);
    }

    in.erase();
    cout << out << "\n";

    return 0;
}