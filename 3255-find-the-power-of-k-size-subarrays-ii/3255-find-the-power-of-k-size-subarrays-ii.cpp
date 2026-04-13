class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1, -1);
        int l = 0, r = 1;

        if(k == 1) {
            while(l < nums.size()) {
                ans[l] = nums[l]; l++;
            }
        }

        else {
            while (r < nums.size()) {
                if (nums[r] - 1 != nums[r - 1]) l = r;
                if (r - l + 1 == k) {
                    ans[l] = nums[r];
                    l++;
                }
                r++;
            }
        }
        
        return ans;
    }
};