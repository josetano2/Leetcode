class Solution {
public:

    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, vector<bool>& cache) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(cache[i]) continue;

            cache[i] = true;
            curr.push_back(nums[i]);
            backtrack(ans, curr, nums, cache);
            curr.pop_back();
            cache[i] = false;
        }
    
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> cache(nums.size(), false);
        backtrack(ans, curr, nums, cache);
        return ans;
    }
};