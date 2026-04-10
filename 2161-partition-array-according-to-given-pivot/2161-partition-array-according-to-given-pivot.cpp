class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> prev, next, mid;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < pivot) prev.push_back(nums[i]);
            else if(nums[i] == pivot) mid.push_back(nums[i]);
            else next.push_back(nums[i]);
        }

        prev.insert(prev.end(), mid.begin(), mid.end());
        prev.insert(prev.end(), next.begin(), next.end());
        return prev;
    }
};