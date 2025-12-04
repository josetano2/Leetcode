class Solution {
public:
    void backtrack(int target, int idx, int currTotal, vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans) {
        if (currTotal == target) {
            ans.push_back(curr);
            return;
        }

        if (currTotal > target)
            return;

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            curr.push_back(candidates[i]);
            backtrack(target, i + 1, currTotal + candidates[i], candidates, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(target, 0, 0, candidates, curr, ans);
        return ans;
    }
};