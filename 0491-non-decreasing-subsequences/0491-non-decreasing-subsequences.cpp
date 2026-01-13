class Solution {
public:

    void backtrack(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, set<vector<int>>& cache) {
        if(curr.size() >= 2) {
            if(cache.find(curr) != cache.end()) return;

            ans.push_back(curr);
            cache.insert(curr);

            if(curr.size() == nums.size()) return;
        }

        for(int i = idx; i < nums.size(); i++) {
            if(!curr.empty() && nums[i] < curr.back()) continue;

            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr, ans, cache);
            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        set<vector<int>> cache;
        backtrack(0, nums, curr, ans, cache);
        return ans;
    }
};