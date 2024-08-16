class Solution {
public:
    int search(vector<int>& nums, int target) {

        int len = nums.size();

        int left = 0, right = len - 1, mid = 0;

        if(len == 1){
            return target == nums[0] ? 0 : -1;
        }

        while(left != right){
            mid = left + (right - left) / 2;
            
            int temp = 0;
            // 4 5 6 7 0 1 2
            // cek apakah target sama mid di side yang sama
            cout << "Left Idx: " << left << endl;
            cout << "Mid Idx: " << mid << endl;
            cout << "Right Idx: " << right << endl << endl;
            cout << "Left: " << nums[left] << endl;
            cout << "Mid: " << nums[mid] << endl;
            cout << "Right: " << nums[right] << endl << endl;

            // 3 >= 1 == 1 >= 1
            if(target >= nums[0] == nums[mid] >= nums[0]){
                temp = nums[mid];
            }
            else{
                if(target < nums[0]){
                    temp = -INT_MAX;
                }
                else{
                    temp = INT_MAX;
                }
            }

            cout << "Temp: " << temp << endl;

            // 1 < 3
            if(temp < target){
                left = mid + 1;
            }
            else if(temp > target){
                right = mid;
            }
            else{
                return mid;
            }

            cout << "Left Idx: " << left << endl;
            cout << "Mid Idx: " << mid << endl;
            cout << "Right Idx: " << right << endl << endl;
            cout << "Left: " << nums[left] << endl;
            cout << "Mid: " << nums[mid] << endl;
            cout << "Right: " << nums[right] << endl << endl;

            cout << "=============" << endl;

            if(target == nums[left]){
                return left;
            }


        }

        return -1;
        
    }
};