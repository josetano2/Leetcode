class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {

        int len = nums.size();
        vector<int> ans(len);
        vector<int> nearest(32, -1);
    
        for(int i = len - 1; i >= 0; i--) {
            for(int j = 0; j < 32; j++) {
                if(nums[i] & (1 << j)) {
                    nearest[j] = i;
                }
            }

            int farthest = i;
            for(int j = 0; j < 32; j++) {
                if(nearest[j] != -1) {
                    farthest = max(farthest, nearest[j]);
                }
            }
            
            ans[i] = farthest - i + 1;
        }

        return ans;
    }
};