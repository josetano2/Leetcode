class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int l = 0, r = 0, ans = INT_MAX;

        while(r < nums.size()) {
            if(r - l + 1 < k) {
                r++;
            }
            else {
                ans = min(ans, nums[r] - nums[l]);
                l++; r++;
            }
        }

        return ans;
    }
};