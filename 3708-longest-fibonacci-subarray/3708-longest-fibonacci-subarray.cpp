class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int count = 2, ans = INT_MIN, n = nums.size();
        if(n == 1 || n == 2) return n;
        
        for(int i = 2; i < n; i++) {
            if(nums[i] == nums[i - 1] + nums[i - 2]) count++;
            else {
                ans = max(count, ans); count = 2;
            }
        }

        return max(count, ans);
    }
};