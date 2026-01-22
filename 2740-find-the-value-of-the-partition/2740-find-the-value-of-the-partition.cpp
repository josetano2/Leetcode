class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {

        // 1 51 59 73 98
        sort(nums.begin(), nums.end());
        
        int ans = INT_MAX;
        for(int i = 0; i < nums.size() - 1; i++) {
            ans = min(ans, nums[i + 1] - nums[i]);
        }

        return ans;
    }
};