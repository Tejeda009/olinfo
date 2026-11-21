#include <bits/stdc++.h>
using namespace std;

class RollingCorr {
	int n = 0;
    double mean_x = 0.0;
    double mean_y = 0.0;
    double m2_x = 0.0;
    double m2_y = 0.0;
    double c_xy = 0.0;

    public:
        RollingCorr() = default;
        ~RollingCorr() = default;

        double update(const double x, const double y) {
            n += 1;

            const double dx = x - mean_x;
            const double dy = y - mean_y;

            mean_x += dx / n;
            mean_y += dy / n;

            const double dx2 = x - mean_x;
            const double dy2 = y - mean_y;

            m2_x += dx * dx2;
            m2_y += dy * dy2;
            c_xy += dx * dy2;

            if (n < 2) {
                return 0.0;
            }

            const double down = sqrt(m2_x * m2_y);

            if (down == 0) return 0.0;
            return c_xy / down;
        }
};