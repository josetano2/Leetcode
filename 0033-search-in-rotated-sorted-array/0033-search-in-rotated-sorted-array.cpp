class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1, mid = 0;

        if(n == 1 && nums[0] == target) return 0;
        while(l < r) {
            mid = l + (r - l) / 2;

            int temp = 0;
            if(target >= nums[0] == nums[mid] >= nums[0]) temp = nums[mid];
            else {
                if(target < nums[0]) temp = INT_MIN;
                else temp = INT_MAX;
            }

            if(temp < target) l = mid + 1;
            else if(temp > target) r = mid;
            else return mid;

            if(target == nums[l]) return l;
        }

        return -1;
    }
};