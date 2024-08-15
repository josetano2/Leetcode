
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();

        int left = 0, right = len - 1, mid = 0;

        // 3 4 5 1 2 mid > left && mid > right -> left = mid + 1
        // 4 5 1 2 3 mid < left && mid < right -> 
        // 5 1 2 3 4 mid < left && mid < right -> right = mid
        // 2 3 4 5 1 mid > left && mid > right -> left = mid + 1

        // 3 1 2 mid < left && mid < right
        // 3 1 mid >= left && mid > right

        while(left != right){
            mid = left + (right - left) / 2;

            cout << "Left Idx: " << left << endl;
            cout << "Mid Idx: " << mid << endl;
            cout << "Right Idx: " << right << endl << endl;
            cout << "Left: " << nums[left] << endl;
            cout << "Mid: " << nums[mid] << endl;
            cout << "Right: " << nums[right] << endl << endl;

            if(nums[left] <= nums[right]){
                return nums[left];
            }

            if(nums[mid] >= nums[left] && nums[mid] > nums[right]){
                left = mid + 1;
            }
            else if(nums[mid] < nums[left] && nums[mid] < nums[right]){
                right = mid;
            }
            else{
                left = mid + 1;
            }

            cout << "Left Idx: " << left << endl;
            cout << "Mid Idx: " << mid << endl;
            cout << "Right Idx: " << right << endl << endl;
            cout << "Left: " << nums[left] << endl;
            cout << "Mid: " << nums[mid] << endl;
            cout << "Right: " << nums[right] << endl << endl;

            cout << "======" << endl;

        }

        int ans = min(nums[left], nums[right]);

        return min(ans, nums[mid]);
    }
};