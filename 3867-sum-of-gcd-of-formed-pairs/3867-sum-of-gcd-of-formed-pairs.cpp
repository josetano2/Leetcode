class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];

        vector<int> prefixGcd(n, 1);
        for (int i = 0; i < n; i++) {
            mx = std::max(nums[i], mx);
            prefixGcd[i] = gcd(mx, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }

        return ans;
    }
};