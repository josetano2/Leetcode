class Solution {
public:

    int cc(vector<int>& dp, vector<int>& coins, int curr) {
        if(curr == 0) return 0;
        if(curr < 0) return INT_MAX - 1;

        if(dp[curr] != INT_MAX - 1) return dp[curr];

        int next = INT_MAX - 1;
        for(int i = 0; i < coins.size(); i++) {
            int temp = cc(dp, coins, curr - coins[i]);
            next = min(temp, next);
        }

        return dp[curr] = next + 1;
    } 

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);
        int ans = cc(dp, coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};