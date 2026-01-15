class Solution {
public:

    int longestStreak(vector<int>& bars) {
        int curr = 1, b = 1;
        for(int i = 0; i < bars.size() - 1; i++) {
            if(bars[i] + 1 == bars[i + 1]) curr++;
            else {
                b = max(curr, b);
                curr = 1;
            }
        }
        return max(curr, b);
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // n -> x, m -> y
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int h = longestStreak(hBars), v = longestStreak(vBars);
        return pow(min(h, v) + 1, 2);
    }
};