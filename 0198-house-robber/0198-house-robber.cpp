class Solution {
public:
    vector<int> cache;

    int dp(vector<int> nums, int idx) {
        if(idx >= nums.size()) return 0;

        if(cache[idx] != -1) return cache[idx];

        return cache[idx] = max(nums[idx] + dp(nums, idx + 2), dp(nums, idx + 1));
    }

    int rob(vector<int>& nums) {
        cache = vector<int>(nums.size(), -1);
        return dp(nums, 0);
    }
};