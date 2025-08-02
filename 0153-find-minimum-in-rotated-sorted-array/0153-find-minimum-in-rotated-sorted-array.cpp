class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l = 0, r = nums.size() - 1, mid = 0;

        // Return L if smaller then right side
        while(l < r) {
            mid = l + ((r - l) / 2);
            if(nums[mid] > nums[r]) {
                l = mid + 1;
            }

            else if(nums[mid] < nums[r]) {
                r = mid;
            }

            if(nums[l] < nums[r]) {
                return nums[l];
            }
        }

        return nums[l];
        
    }
};