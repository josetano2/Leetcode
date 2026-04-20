class Solution {
public:

    int cc(vector<int>& dp, vector<int>& coins, int curr) {
        if(curr < 0) return INT_MAX;
        if(curr == 0) return 0;

        if(dp[curr] != -1) return dp[curr];

        int next = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int temp = cc(dp, coins, curr - coins[i]);
            if(temp != INT_MAX) next = min(temp + 1, next);
        }

        return dp[curr] = next;
    } 

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = cc(dp, coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};