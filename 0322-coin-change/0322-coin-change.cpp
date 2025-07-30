class Solution {
public:
    // 1 2 5
    // 0 -> 0
    // 1 -> 1
    // 2 ->

    vector<int> cache;

    int dp(vector<int>& coins, int idx) {
        if (idx < 0) {
            return INT_MAX;
        }

        if (idx == 0) {
            return 0;
        }

        if (cache[idx] != -1) {
            return cache[idx];
        }

        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int temp = dp(coins, idx - coins[i]);
            if (temp != INT_MAX)
                res = min(res, temp + 1);
        }

        cache[idx] = res;
        return cache[idx];
    }

    int coinChange(vector<int>& coins, int amount) {
        cache = vector<int>(amount + 1, -1);
        int ans = dp(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};