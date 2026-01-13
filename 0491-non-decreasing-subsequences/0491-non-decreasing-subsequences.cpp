class Solution {
public:

    void backtrack(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if(curr.size() >= 2) {
            ans.push_back(curr);
        }

        unordered_set<int> cache;

        for(int i = idx; i < nums.size(); i++) {
            if(!curr.empty() && nums[i] < curr.back()) continue;
            if(cache.find(nums[i]) != cache.end()) continue;

            cache.insert(nums[i]);
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, nums, curr, ans);
        return ans;
    }
};