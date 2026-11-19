#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int applicants, apartments, diff;
    cin >> applicants >> apartments >> diff;

    vector<int> desired(applicants);
    for (int i = 0; i < applicants; i++) {
        cin >> desired[i];
    }

    vector<int> sizes(apartments);
    for (int i = 0; i < apartments; i++) {
        cin >> sizes[i];
    }

    sort(desired.begin(), desired.end());
    sort(sizes.begin(), sizes.end());

    int i = 0; 
    int j = 0; 
    int cont = 0;

    while (i < apartments && j < applicants) {
        if (abs(sizes[i] - desired[j]) <= diff) {
            cont++;
            i++;
            j++;
        } else if (sizes[i] < desired[j] - diff) {
            i++;
        } else {
            j++;
        }
    }

    cout << cont << '\n';
    return 0;
}
