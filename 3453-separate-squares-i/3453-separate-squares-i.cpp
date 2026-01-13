class Solution {
public:
    double calculateAreaBelowMid(vector<vector<int>>& squares, double y) {
        double tot = 0;
        for (auto& s : squares) {
            if (y <= s[1]) {
                tot += 0;
            } else if (y >= s[1] + s[2]) {
                tot += (double) s[2] * s[2];
            } else {
                tot += (double) s[2] * (y - s[1]);
            }
        }
        return tot;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double l = DBL_MAX, r = DBL_MIN, area = 0;

        for (auto& s : squares) {
            if (s[1] < l)
                l = s[1];
            if (s[1] + s[2] > r)
                r = s[1] + s[2];

            area += (double) s[2] * s[2];
        }
        area /= 2;

        while (r - l > 1e-6) {
            double mid = l + ((r - l) / 2.0);
            if (calculateAreaBelowMid(squares, mid) < area)
                l = mid;
            else
                r = mid;
        }

        return l;
    }
};