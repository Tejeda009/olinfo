#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, total = 0;
    cin >> N;

    vector<long long> start(N);
    vector<long long> end(N);

    for (long long i = 0; i < N; i++) {
        long long currstart, currend;
        cin >> currstart >> currend;
        start[i] = currstart;
        end[i] = currend;
    }

    vector<long long> startcopy = start;
    vector<long long> endcopy = end;

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    const long long startSquare = (start.size() % 2 == 0) ? start[(start.size() / 2) - 1] : start[(start.size() / 2)];
    const long long endSquare = (end.size() % 2 == 0) ? end[(end.size() / 2) - 1] : end[(end.size() / 2)];


    /*cout << '\n' << "Dati: " << '\n';
    cout << startSquare << '\n' << endSquare << '\n';
    cout << '\n';*/

    long long prev = 0;

    for (long long i = 0; i < N; i++) {
        prev = total;
        if (startSquare > startcopy[i]) {
            total += abs(startSquare - startcopy[i]);
            total += abs(startcopy[i] - endcopy[i]);
        } else {
            total += abs(startSquare - startcopy[i]);
            total += abs(startcopy[i] - endcopy[i]);
        }
        total += abs(endcopy[i] - endSquare);
        
        //cout << '\n' << "Valore di " << i + 1 << " : " << total - prev << '\n';
    }

    cout << total << '\n';

    return 0;
}