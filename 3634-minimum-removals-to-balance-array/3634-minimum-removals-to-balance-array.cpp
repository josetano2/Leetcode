class Solution {
public:
    int minRemoval(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int j = upper_bound(nums.begin(), nums.end(), (long long) nums[i] * k) - nums.begin() - 1;
            ans = min(ans, n - (j - i) - 1);
        }
        return ans;
    }
};