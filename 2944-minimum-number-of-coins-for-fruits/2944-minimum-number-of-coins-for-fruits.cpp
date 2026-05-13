class Solution {
public:
    int dp(int idx, vector<int>& cache, vector<int>& prices) {
        if(idx >= prices.size()) return 0;
        if(cache[idx] != INT_MAX) return cache[idx];

        int temp = INT_MAX;
        for(int j = idx + 1; j <= 2 * idx + 2; j++) temp = min(temp, dp(j, cache, prices));
        return cache[idx] = temp + prices[idx];
    }

    int minimumCoins(vector<int>& prices) {
        vector<int> cache(prices.size(), INT_MAX);
        return dp(0, cache, prices);
    }
};