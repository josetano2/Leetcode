class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.size() - 1;
        long long ans = 0;
        while(l <= r) {
            ans += pow(nums[r], 2);
            r--;

            if(l <= r) {
                ans -= pow(nums[l], 2);
                l++;
            }
        }
        return ans;
    }
};