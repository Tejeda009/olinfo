#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Ottimizzazione dell'I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    long long sum;
    if (!(cin >> size >> sum)) return 0;

    vector<long long> a(size);
    for (int i = 0; i < size; ++i) {
        cin >> a[i];
    }

    //    sum      frequency
    map<long long, long long> prefix_counts;
    
    // first sum
    prefix_counts[0] = 1;

    long long current_sum = 0;
    long long count = 0;

    for (int i = 0; i < size; ++i) {
        current_sum += a[i];

        // if the prefix sum was already seen increment the counter
        if (prefix_counts.count(current_sum - sum)) {
            count += prefix_counts[current_sum - sum];
        }

        // increment the frequency of this prefix sum
        prefix_counts[current_sum]++;
    }

    cout << count << "\n";

    return 0;
}
