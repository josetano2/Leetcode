class Solution {
public:
    int climbStairs(int n) {

        if(n == 0) return 0;
        if(n == 1) return 1;

        int dp[n + 1];

        // n = 5

        dp[n] = 1; // dp[5] = 1
        dp[n - 1] = 1; // dp[4] = 1
        // dp[3] = 2
        // dp[2] = 3
        // dp[1] = 5

        for(int i = n - 2; i >= 0; i--){
            dp[i] = dp[i + 1] + dp[i + 2];
        }

        return dp[0];
        
    }
};