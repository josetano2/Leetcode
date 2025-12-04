class Solution {
public:
    void backtrack(int target, int idx, int currTotal, vector<int>& candidates,
                   vector<int>& curr, vector<vector<int>>& ans,
                   set<vector<int>>& cache) {
        if (currTotal == target) {
            if (!cache.count(curr)) {
                ans.push_back(curr);
                cache.insert(curr);
            }
            return;
        }

        if (currTotal > target)
            return;

        for (int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(target, i + 1, currTotal + candidates[i], candidates,
                      curr, ans, cache);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        set<vector<int>> cache;
        backtrack(target, 0, 0, candidates, curr, ans, cache);
        return ans;
    }
};