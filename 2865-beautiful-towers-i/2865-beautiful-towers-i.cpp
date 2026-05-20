class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        long long ans = -1;

        for(int i = 0; i < n; i++) {
            long long c = heights[i];
            int lm = INT_MAX;
            for(int j = i - 1; j >= 0; j--) {
                lm = min({heights[i], heights[j], lm});
                c += lm;
            }
            
            int rm = INT_MAX;
            for(int j = i + 1; j < n; j++) {
                rm = min({heights[i], heights[j], rm});
                c += rm;
            }
            ans = max(c, ans);
        }

        return ans;
    }
};