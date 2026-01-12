class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size() - 1; i++) {
            vector<int> curr = points[i];
            vector<int> next = points[i + 1];

            int xDiff = abs(curr[0] - next[0]), yDiff = abs(curr[1] - next[1]);
            ans += max(xDiff, yDiff);
        }
        return ans;
    }
};