#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int N;

    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> N;

    vector<int> num(N);

    int max = -1, ris = 1;
    int index = 0;

    for (int i = 0; i < N; i++) {
        in >> num[i];
        if (num[i] > max) {
            max = num[i];
            index = i;
        }
    }

    for (int i = index + 1; i < N; i++) {
        if (num[i] <= max) {
            ris++;
        }
    }

    out << ris << endl;

    in.close();
    out.close();
    return 0;
}