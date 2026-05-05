class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // hold + sell -> cool
        // hold + skip -> hold
        // free + buy -> hold
        // free + skip -> free
        // cool + skip -> free
        int n = prices.size();
        vector<int> hold(n, INT_MIN);
        vector<int> free(n, INT_MIN);
        vector<int> cool(n, INT_MIN);

        hold[0] = -prices[0];
        free[0] = 0;
        cool[0] = INT_MIN;

        for(int i = 1; i < n; i++) {
            hold[i] = max(hold[i - 1], free[i - 1] - prices[i]);
            free[i] = max(free[i - 1], cool[i - 1]);
            cool[i] = hold[i - 1] + prices[i];
        }

        return max({hold[n - 1], free[n - 1], cool[n - 1]});
    }
};