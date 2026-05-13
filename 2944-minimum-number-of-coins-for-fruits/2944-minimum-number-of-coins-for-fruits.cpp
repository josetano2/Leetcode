class Solution {
public:
    int dp(int idx, int free, vector<vector<int>>& cache, vector<int>& prices) {
        if(idx >= prices.size()) return 0;

        if(free == -1) return cache[idx][0] = dp(idx + 1, 2 * idx + 1, cache, prices) + prices[idx];
        if(cache[idx][free] != INT_MAX) return cache[idx][free];

        int freeFruit = -1, paidFruit = -1;
        if(idx <= free) {
            freeFruit = dp(idx + 1, free, cache, prices);
        }
        paidFruit = dp(idx + 1, 2 * idx + 1, cache, prices) + prices[idx];

        if(freeFruit == -1) cache[idx][free] = paidFruit;
        else cache[idx][free] = min(freeFruit, paidFruit);
        
        return cache[idx][free];
    }

    int minimumCoins(vector<int>& prices) {
        vector<vector<int>> cache(prices.size(), vector<int>(prices.size() * 2, INT_MAX));
        
        int ans = dp(0, -1, cache, prices);
        return ans;
    }
};