class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        if(sorted == nums) return 0;

        int l = 0, r = nums.size() - 1;
        while(l < r) {
            if(nums[l] == sorted[l]) l++;
            if(nums[r] == sorted[r]) r--;

            if(nums[l] != sorted[l] && nums[r] != sorted[r]) return r - l + 1;
        }

        return r - l + 1;
    }
};