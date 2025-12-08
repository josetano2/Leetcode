class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        int count = 0, peak = INT_MIN;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                if(count == 0) {
                    count++;
                    if(i > 0) {
                        int prev = nums[i - 1], curr = nums[i], next = nums[i + 1];
                        if(next >= prev) nums[i] = next;
                        if(prev > next) nums[i + 1] = curr;
                    }
                    if(i == 0) nums[i] = nums[i + 1] - 1;
                }
                else return false;
            }
            peak = max(nums[i], peak);
            if(nums[i + 1] < peak && count == 1) return false;
        }
        return true;
    }
};