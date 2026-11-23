#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tickets, customers;
    cin >> tickets >> customers;

    vector<int> prices(tickets);
    vector<int> maxes(customers);

    for (auto& el : prices) {
        cin >> el;
    }

    for (auto& el : maxes) {
        cin >> el;
    }

    sort(prices.begin(), prices.end(), std::greater<int>());
    sort(maxes.begin(), maxes.end(), std::greater<int>());

    size_t cont = 0;

    for (size_t i = 0; i < tickets; i++) {

        if (maxes[cont] <= prices[i]) {
            cout << prices[i] << "\n";
            cont++;
        }

    }

    for (int i = 0; i < (customers - cont); i++) {
        cout << "-1\n";
    }

    return 0;
}