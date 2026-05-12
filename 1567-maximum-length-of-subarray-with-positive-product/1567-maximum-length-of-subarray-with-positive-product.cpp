class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, INT_MIN));

        
        if(nums[0] > 0){
            dp[0][0] = 1;
            dp[0][1] = 0;
        }
        else if(nums[0] < 0) {
            dp[0][0] = 0;
            dp[0][1] = 1;
        }
        else {
            dp[0][0] = 0;
            dp[0][1] = 0;
        }


        int ans = dp[0][0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > 0) {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1] > 0 ? dp[i - 1][1] + 1 : 0;
            }
            else if(nums[i] < 0) {
                dp[i][1] = dp[i - 1][0] + 1;
                dp[i][0] = dp[i - 1][1] > 0 ? dp[i - 1][1] + 1 : 0;
            }
            else {
                dp[i][0] = 0;
                dp[i][1] = 0;
            }
            ans = max(ans, dp[i][0]);
            
        }
        return ans;
        
    }
};