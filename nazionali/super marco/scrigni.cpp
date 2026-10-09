#include <stdio.h>
#include <iostream>
#include <assert.h>

using namespace std;

double scosse(int N) {
    return (static_cast<double>(N - 1) * N) / 4.0;  
}


int main() {
    //FILE *fr, *fw;
    int N;

    cin >> N;
    cout << scosse(N);

    //fr = fopen("input.txt", "r");
    //fw = fopen("output.txt", "w");
    //assert(1 == fscanf(fr, "%d", &N));
    //fprintf(fw, "%.6f\n", scosse(N));
    //fclose(fr);
    //fclose(fw);
    return 0;
}
