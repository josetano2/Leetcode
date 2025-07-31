class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int l = 0, r = 0, curr = 0, ans = INT_MAX;

        while (r < nums.size()) {
            if (r < nums.size()) {
                curr += nums[r];
                if (curr < target) {
                    r++;
                } else {
                    while(curr - nums[l] >= target) {
                        curr -= nums[l];
                        l++;
                    }
                    ans = min(ans, r - l + 1);
                    r++;
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};