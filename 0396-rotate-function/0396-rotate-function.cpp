class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int sum = 0, tot = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            tot += nums[i];
            sum = sum + (i * nums[i]);
        }

        int ans = sum;
        for(int i = 1; i < n; i++) {
            sum = sum + tot - (n * nums[n - i]);
            ans = max(sum, ans);
        }

        return ans;
    }
};