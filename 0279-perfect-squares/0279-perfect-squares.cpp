class Solution {
public:

    vector<int> nums;
    vector<int> dp;

    int calculate(int idx) {
        if(idx == 0) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int temp = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(idx - nums[i] < 0) continue;
            int res = calculate(idx - nums[i]);
            if(res != INT_MAX) {
                temp = min(temp, res + 1);
            }
        }

        dp[idx] = temp;
        return dp[idx];
    }

    int numSquares(int n) {
        dp = vector<int>(n + 1, -1);
        for(int i = 1; i * i <= n; i++){
            nums.push_back(i * i);
        }
        return calculate(n);
    }
};