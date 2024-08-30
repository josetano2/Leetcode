class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0, fast = 0;

        do{
            slow = nums[slow];

            fast = nums[fast];
            fast = nums[fast];
        }while(slow != fast);

        int start = 0;

        do{
            slow = nums[slow];
            start = nums[start];
        }while(start != slow);

        cout << slow << " " << fast << endl;

        return slow;


    }
};