class Solution {
public:

    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(find(curr.begin(), curr.end(), nums[i]) != curr.end()) continue;
            curr.push_back(nums[i]);
            backtrack(ans, curr, nums);
            curr.pop_back();
        }
    
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, nums);
        return ans;
    }
};