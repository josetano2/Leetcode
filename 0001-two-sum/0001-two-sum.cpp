class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> ansMap;

        int len = nums.size();

        for (int i = 0; i < len; i++) {
            int res = target - nums[i];
            if (ansMap[nums[i]] == 0) {
                ansMap[res] = i + 1;
            } else {
                ans.push_back(ansMap[nums[i]] - 1);
                ans.push_back(i);
            }
        }

        return ans;
    }
};