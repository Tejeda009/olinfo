#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int ret = 7;
    string in = "";

    cin >> in;
    int a, b, c, d;
    a = in[0] - '0';
    b = in[1] - '0';
    c = in[2] - '0';
    d = in[3] - '0';

    if ((a + b + c + d) == ret) {
        cout << a << "+" << b << "+" << c << "+" << d << "=7\n";
    } else if ((a - b + c + d) == ret) {
        cout << a << "-" << b << "+" << c << "+" << d << "=7\n";
    } else if ((a - b - c + d) == ret) {
        cout << a << "-" << b << "-" << c << "+" << d << "=7\n";
    } else if ((a + b - c + d) == ret) {
        cout << a << "+" << b << "-" << c << "+" << d << "=7\n";
    } else if ((a + b - c - d) == ret) {
        cout << a << "+" << b << "-" << c << "-" << d << "=7\n";
    } else if ((b + c + d - a) == ret) {
        cout << b << "+" << c << "+" << d << "-" << a << "=7\n";
    } else if ((b + c - d - a) == ret) {
        cout << b << "+" << c << "-" << d << "-" << a << "=7\n";
    } else if ((b - c - d - a) == ret) {
        cout << b << "-" << c << "-" << d << "-" << a << "=7\n";
    } else if ((b + c + a - d) == ret) {
        cout << b << "+" << c << "+" << a << "-" << d << "=7\n";
    } else if ((b + c - a - d) == ret) {
        cout << b << "+" << c << "-" << a << "-" << d << "=7\n";
    } else if ((b - c - a - d) == ret) {
        cout << b << "-" << c << "-" << a << "-" << d << "=7\n";
    } else if ((a + b + d - c) == ret) {
        cout << a << "+" << b << "+" << d << "-" << c << "=7\n";
    } else if ((a + b - d - c) == ret) {
        cout << a << "+" << b << "-" << d << "-" << c << "=7\n";
    } else if ((a - b - d - c) == ret) {
        cout << a << "-" << b << "-" << d << "-" << c << "=7\n";
    } else if ((d + c + a - b) == ret) {
        cout << d << "+" << c << "+" << a << "-" << b << "=7\n";
    } else if ((d + c - a - b) == ret) {
        cout << d << "+" << c << "-" << a << "-" << b << "=7\n";
    } else if ((d - c - a - b) == ret) {
        cout << d << "-" << c << "-" << a << "-" << b << "=7\n";
    } else {
        cout << "-1\n"; 
    }


    return 0;
}