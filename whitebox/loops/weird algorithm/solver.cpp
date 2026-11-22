#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    while(n != 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n/=2;
        } else {
            n*=3;
            n+=1;
        }
    }

    cout << "1\n";

    return 0;
}
/*



*/
//7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 