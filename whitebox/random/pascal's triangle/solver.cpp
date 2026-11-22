#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> generate(const int numRows) {
        if (numRows <= 0) return {};

        vector<vector<int>> rows;
        rows.reserve(numRows);

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; ++j) {
                row[j] = rows[i - 1][j - 1] + rows[i - 1][j];
            }

            rows.push_back(std::move(row));
        }

        return rows;
    }
};
