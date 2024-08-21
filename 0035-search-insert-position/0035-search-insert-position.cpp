class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size(), left = 0, right = len - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            cout << nums[mid] << endl;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
        }

        return left;
        
    }
};