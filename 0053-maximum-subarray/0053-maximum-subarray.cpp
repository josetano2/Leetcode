class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int idx = 0, ans = -1000000, len = nums.size(), currTot = 0;
        
        for (int i = 0; i < len; i++) {
            // currTot = -3
            currTot = max(nums[i], currTot + nums[i]);
            ans = max(ans, currTot);
        }

        return ans;
    }
};
