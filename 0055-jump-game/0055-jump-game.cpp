class Solution {
public:
    // Greedy
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        int goalDist = len - 1;
        for(int i = len - 2; i > 0; i--) {
            if(nums[i] >= goalDist - i) {
                goalDist = i;
            }
        }

        return nums[0] >= goalDist;
    }

    // DP Approach
    // vector<int> cache;

    // bool dp(int idx, vector<int>& nums) {

    //     if (idx >= nums.size() - 1) {
    //         return true;
    //     }

    //     if(cache[idx] != -1) {
    //         return cache[idx];
    //     }

    //     for(int i = 1; i <= nums[idx]; i++) {
    //         if(dp(idx + i, nums)) {
    //             return cache[idx] = true;
    //         }
    //     }
    //     return cache[idx] = false;
    // }

    // bool canJump(vector<int>& nums) {
    //     cache = vector<int>(nums.size(), -1);

    //     bool x = dp(0, nums);
    //     return dp(0, nums);
    // }
};