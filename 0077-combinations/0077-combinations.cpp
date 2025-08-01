class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int idx, int n, int k, vector<int> curr) {
        if (curr.size() == k) {
            ans.push_back(vector<int>(curr));
        }

        for (int i = idx; i <= n; i++) {
            curr.push_back(i);
            backtrack(i + 1, n, k, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(1, n, k, curr);
        return ans;
    }
};