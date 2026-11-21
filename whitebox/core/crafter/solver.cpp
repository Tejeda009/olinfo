#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <iostream>

class CraftingEngine {
public:
    int base_durability;
    std::vector<std::pair<int, int>> additions;

    CraftingEngine(const int base_durability) : base_durability(base_durability) {}

    void add(const int cost, const int damage) {
        additions.emplace_back(cost, damage);
    }

    int countReplacements(const int threshold) const { 
        int consecutive_poor_materials = 0;
        int result = 0;

        for (const auto& [cost, damage] : additions) {
            if (cost > damage) {
                consecutive_poor_materials++;
                if (consecutive_poor_materials == threshold) {
                    consecutive_poor_materials = 0;
                    result++;
                }
            } else {
                consecutive_poor_materials = 0; 
            }
        }
        return result;
    }

    int maximumDamage(const int min_durability) const {
        const int capacity = base_durability - min_durability;

        std::vector<int> dp(capacity + 1, 0);

        for (const auto& [cost, damage] : additions) {
            for (int w = capacity; w >= cost; --w) {
                dp[w] = std::max(
                    dp[w],
                    dp[w - cost] + damage
                );
            }
        }

        return dp[capacity];
    }
};


int main() {
    CraftingEngine test(10);

    test.add(3, 2);
    test.add(1, 5);
    test.add(4, 1);
    test.add(2, 1);
    test.add(1, 3);

    std::cout << test.countReplacements(2) << "\n";
    std::cout << test.maximumDamage(5) << '\n';


    return 0;
}