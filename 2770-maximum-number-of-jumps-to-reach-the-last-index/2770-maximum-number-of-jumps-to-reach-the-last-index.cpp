class Solution {
public:

    int dp(vector<int>& nums, vector<int>& cache, int target, int i) {
        if(i >= nums.size()) return -1;
        if(i == nums.size() - 1) return 0;

        if(cache[i] != INT_MIN) return cache[i];

        int temp = INT_MIN;
        for(int j = i + 1; j < nums.size(); j++) {
            if(abs(nums[j] - nums[i]) > target) continue;

            temp = max(temp, dp(nums, cache, target, j));
        }

        return cache[i] = temp + 1;
    }

    int maximumJumps(vector<int>& nums, int target) {
        vector<int> cache(nums.size(), INT_MIN);
        int ans = dp(nums, cache, target, 0);
        return ans < 0 ? -1 : ans;
    }
};