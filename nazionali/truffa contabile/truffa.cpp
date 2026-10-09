#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>

using namespace std;

int sfangate(int N, vector<int> &V, int sum) {
    sort(V.begin(), V.end());
    int count = 0;

    while (sum <= 0 && count < V.size()) {
        sum-= (V[count]*2);
        count++;
    }

    return count;
}


vector<int> V;
int var;

int main() {
    FILE *fr, *fw;
    int N, i, sum = 0;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++) {
        fscanf(fr, "%d", &var);
        if (var < 0) {
            V.push_back(var);
        }
        sum += var;
    }

    fprintf(fw, "%d\n", sfangate(N, V, sum));
    fclose(fr);
    fclose(fw);
    return 0;
}