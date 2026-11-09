#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    int cont = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            const int dx = abs(points[j].x - points[i].x);
            const int dy = abs(points[j].y - points[i].y);

            if (dy <= dx) {
                cont++;
            }
        }
    }

    cout << cont << "\n";

    return 0;
}