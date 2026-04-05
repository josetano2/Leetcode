class Solution {
public:

    void create(string curr, int open, int close, int n, vector<string>& ans) {
        if(open == n && close == n) ans.push_back(curr);
        if(open < n) create(curr + "(", open + 1, close, n, ans);
        if(close < open) create(curr + ")", open, close + 1, n, ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        create("(", 1, 0, n, ans);
        return ans;
    }
};