class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int low = -1, il = 0, high = -1, ih = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                low = max(low, i - il + 1);
                il = i + 1;
            }

            if (nums[i] <= nums[i + 1]) {
                high = max(high, i - ih + 1);
                ih = i + 1;
            }
        }

        low = max(low, n - il);
        high = max(high, n - ih);

        return max(low, high);
    }
};