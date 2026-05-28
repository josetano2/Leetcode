class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        long long sum1 = 0, n = nums.size(), sum2 = 0, ans = INT_MAX, idx = -1;
        for(auto& x : nums) sum1 += x;

        for(int i = 0; i < n; i++) {
            int x1 = 0, x2 = 0;

            x1 = sum1 / (n - i);
            x2 = i == 0 ? 0 : sum2 / i;
            
            int diff = abs(x1 - x2);
            if(diff <= ans) {
                ans = diff;
                idx = i;
            }

            sum1 -= nums[n - i - 1];
            sum2 += nums[n - i - 1];
            
        }

        return n - idx - 1;
    }
};