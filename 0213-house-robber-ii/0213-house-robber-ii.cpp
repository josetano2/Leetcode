class Solution {
public:
    int dp(vector<int>& nums, int idx, int limit, vector<int>& cache) {
        if(idx >= limit) return 0;
        if(cache[idx] != -1) return cache[idx];
        return cache[idx] = max(nums[idx] + dp(nums, idx + 2, limit, cache), dp(nums, idx + 1, limit, cache));
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> cache1 = vector<int>(nums.size(), -1);
        vector<int> cache2 = vector<int>(nums.size(), -1);
        return max(dp(nums, 0, nums.size() - 1, cache1), dp(nums, 1, nums.size(), cache2));
    }
};