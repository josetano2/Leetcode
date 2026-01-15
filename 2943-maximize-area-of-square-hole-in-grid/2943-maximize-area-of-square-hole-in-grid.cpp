class Solution {
public:

    int longestStreak(vector<int>& bars) {
        sort(bars.begin(), bars.end());

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
        int h = longestStreak(hBars), v = longestStreak(vBars);
        return pow(min(h, v) + 1, 2);
    }
};