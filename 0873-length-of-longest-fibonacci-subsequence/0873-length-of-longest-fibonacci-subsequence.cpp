class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        unordered_map<int, int> um;

        for(int i = 0; i < n; i++) um[arr[i]] = i;

        int ans = INT_MIN;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int target = arr[i] - arr[j];
                if(um.find(target) != um.end() && um[target] < j) {
                    dp[j][i] = max(dp[j][i], dp[um[target]][j] + 1);
                    ans = max(dp[j][i], ans);
                }
            }
        }

        return ans < 3 ? 0 : ans;
    }
};