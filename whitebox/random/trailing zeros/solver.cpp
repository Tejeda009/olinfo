#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    if (!(std::cin >> n)) return 0;

    long long cont = 0;

    while (n >= 5) {
        n /= 5;
        cont += n;
    }

    std::cout << cont << "\n";
    return 0;
}
