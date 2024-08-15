class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();

        unordered_map<int, bool> numMap;
        // tes

        for(int i = 0; i < len; i++){
            if(numMap[nums[i]]){
                return true;
            }
            numMap[nums[i]] = true;
        }
        return false;
    }
};