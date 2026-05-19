class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), pivot = -1;
        for(int i = n - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                pivot = i - 1; break;
            }
        }

        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int swapI = 0;
        for(int i = n - 1; i > 0; i--) {
            if(nums[i] > nums[pivot]) {
                swapI = i;
                break;
            }
        }

        swap(nums[pivot], nums[swapI]);
        reverse(nums.begin() + pivot + 1, nums.end());
        return;
    }
};