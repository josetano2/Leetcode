class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e09 + 7;
        vector<long long> pfix(n, 0);
        pfix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            pfix[i] = pfix[i - 1] + nums[i];
        }

        vector<long long> all;
        int mul = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                all.push_back(pfix[j] - mul);
            }
            mul = pfix[i];
        }

        sort(all.begin(), all.end());
        long long ans = 0;
        for(int i = left - 1; i < right; i++) {
            ans += all[i] % MOD;
        }
        return ans % MOD;
    }
};