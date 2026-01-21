class Solution {
public:

    int dp(int l, int r, vector<vector<int>>& cache, vector<int>& nums) {
        
        if(l > r) return 0;
        if(cache[l][r] != -1) return cache[l][r];

        int maxCoins = INT_MIN;
        for(int i = l; i <= r; i++) {
            int coins = nums[l - 1] * nums[i] * nums[r + 1] + dp(i + 1, r, cache, nums) + dp(l, i - 1, cache, nums);
            maxCoins = max(maxCoins, coins);
        }
        
        cache[l][r] = maxCoins;
        return maxCoins;
    }

    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); nums.push_back(1);
        int l = 1, r = nums.size() - 2;
        vector<vector<int>> cache(nums.size(), vector<int>(nums.size(), -1));
        
        return dp(l, r, cache, nums);
    }
};