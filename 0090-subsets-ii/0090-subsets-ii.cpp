class Solution {
public:
    set<vector<int>> unique;
    vector<vector<int>> ans;

    void backtrack(int idx, vector<int>& curr, vector<int>& nums) {
        if (idx >= nums.size()) {
            if (!unique.count(curr)) {
                ans.push_back(vector<int>(curr));
                unique.insert(vector<int>(curr));
            }
            return;
        }
        curr.push_back(nums[idx]);
        backtrack(idx + 1, curr, nums);

        curr.pop_back();
        backtrack(idx + 1, curr, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(0, curr, nums);
        return ans;
    }
};