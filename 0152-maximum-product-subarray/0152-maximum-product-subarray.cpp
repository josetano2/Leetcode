class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int ans = INT_MIN, currTotMax = 0, currTotMin = 0;

        for (auto& x : nums) {
            int tempMax = currTotMax, tempMin = currTotMin;

            currTotMax = max({ x, tempMax * x, tempMin * x});
            currTotMin = min({ x, tempMax * x, tempMin * x});

            ans = max(ans, currTotMax);
        }
        return ans;
    }
};