#include <bits/stdc++.h>
using namespace std;

struct rist {
    string city;
    int points;
    int id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    
    vector<rist> restaurants(size);
    for (int i = 0; i < size; i++) {
        cin >> restaurants[i].city >> restaurants[i].points;
        restaurants[i].id = i + 1;
    }

    sort(restaurants.begin(), restaurants.end(), [](const rist& a, const rist& b) {
        if (a.city != b.city) {
            return a.city < b.city;
        }
        return a.points > b.points;
    });

    for (const auto& r: restaurants) {
        cout << r.id << '\n';
    }


    return 0;
}