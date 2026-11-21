#include <bits/stdc++.h>
using namespace std;

class RollingCorr {
	std::vector<double> xP;
    std::vector<double> yP;

    public:
        RollingCorr() = default;
        ~RollingCorr() = default;

        double update(const double x, const double y) {
            xP.push_back(x);
            yP.push_back(y);

            if (xP.size() < 2 || yP.size() < 2) {
                return 0.0;
            }

            const size_t n = xP.size();

            const double somma_x = std::accumulate(xP.begin(), xP.end(), 0.0);
            const double somma_y = std::accumulate(yP.begin(), yP.end(), 0.0);

            const double media_x = somma_x / n;
            const double media_y = somma_y / n;
        
            double cod = 0;
            double right_down = 0;
            double left_down = 0;

            for (size_t i = 0; i < n; ++i) {
                const double x_calc = xP[i] - media_x;
                const double y_calc = yP[i] - media_y;

                cod += (x_calc) * (y_calc);

                right_down += pow(x_calc, 2);
                left_down += pow(y_calc, 2);
            }

            const double down = sqrt(right_down) * sqrt(left_down);
            if (down == 0) return 0.0;
            return cod / down;
        }
};