class Solution {
public:

    void backtrack(vector<vector<int>>& ans, vector<int>& curr, int currTot, vector<int>& cand, int target, int start) {
        
        if(currTot == target) {
            ans.push_back(curr);
            return;
        }

        if(currTot > target) return;

        for(int i = start; i < cand.size(); i++) {
            curr.push_back(cand[i]);
            backtrack(ans, curr, currTot + cand[i], cand, target, i);
            curr.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, 0, candidates, target, 0);
        return ans;
    }
};