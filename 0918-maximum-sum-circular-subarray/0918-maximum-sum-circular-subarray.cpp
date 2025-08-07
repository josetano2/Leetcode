class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maxSum = INT_MIN, minSum = INT_MAX, len = nums.size(), currTotMin = 0, currTotMax = 0, tot = 0;

        for(int i = 0; i < nums.size(); i++) {
            tot += nums[i];
            currTotMax = max(nums[i], currTotMax + nums[i]);
            maxSum = max(maxSum, currTotMax);

            currTotMin = min(nums[i], currTotMin + nums[i]);
            minSum = min(minSum, currTotMin);
        }
        cout << maxSum << " " << minSum << endl;

        return maxSum < 0 ? maxSum : max(maxSum, tot - minSum);
    }
};