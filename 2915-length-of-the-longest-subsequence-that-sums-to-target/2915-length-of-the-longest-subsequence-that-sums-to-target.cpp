class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);

        int n = nums.size();
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = target; j >= nums[i]; j--) {
               if(dp[j - nums[i]] != -1) dp[j] = max(dp[j], 1 + dp[j - nums[i]]);
            }
        }
        return dp[target];
    }
};