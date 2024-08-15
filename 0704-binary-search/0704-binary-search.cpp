class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        int left = 0, right = len - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            cout << nums[mid] << endl;
            if(target == nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1; 
            }
        }

        return -1;
    }
};