#include <bits/stdc++.h>
using namespace std;

int getNumberDivisors(int n) {
    int cont = 0;
    for(int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cont++;
        }
    }

    return cont;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cont = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1)
            if(getNumberDivisors(i) == 8) cont++;
    }

    cout << cont << "\n";

    return 0;
}