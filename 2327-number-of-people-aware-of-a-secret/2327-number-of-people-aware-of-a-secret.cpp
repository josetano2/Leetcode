class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long int> dp(n + 1, 0);

        dp[1] = 1;
        long long int MOD = 1000000007;
        long long int know = 0;
        for (int i = 2; i <= n; i++) {
            int delayIdx = i - delay >= 0 ? i - delay : 0;
            int forgetIdx = i - forget >= 0 ? i - forget : 0;
            long long int spread = dp[delayIdx];
            long long int forget = dp[forgetIdx];

            cout << know + spread - forget << endl;
            dp[i] = (((know + spread - forget) % MOD) + MOD) % MOD;
            know = dp[i];
        }

        long long int tot = 0;
        for(int i = n - forget + 1; i <= n; i++) tot += dp[i];

        return tot % 1000000007;
    }
};