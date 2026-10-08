#include <iostream>

using namespace std;


int main() {
    int N, ris = -1;

    cin >> N;


    for (int i = 0; i < N; i++) {
        int n1, n2;
        cin >> n1;
        cin >> n2;

        int guess = n1 + n2;
        if (guess % 2 == 0 && guess > ris) {
            ris = guess;
        }
    }
    cout << ris << endl;

    return 0;
}