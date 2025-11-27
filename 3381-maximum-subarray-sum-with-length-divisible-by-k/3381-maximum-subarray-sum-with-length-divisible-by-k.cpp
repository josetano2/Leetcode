class Solution {
public:
    long long int MOD = 100000007;
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long int> minPrefix(k, LLONG_MAX);
        vector<long long int> prefixSum(nums.size() + 1, 0);
        long long int ans = LLONG_MIN;

        prefixSum[0] = 0;
        minPrefix[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            prefixSum[i] = nums[i - 1] + prefixSum[i - 1];
            int currIdxMod = i % k;

            if (i >= k) {
                long long int curr = prefixSum[i] - minPrefix[currIdxMod];
                if(curr > ans) ans = curr;
            }
            minPrefix[currIdxMod] = min(minPrefix[currIdxMod], prefixSum[i]);
        }
        return ans;
    }
};