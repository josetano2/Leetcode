class Solution {
public:
    bool isValid(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            r--;
            l++;
        }
        return true;
    }

    void backtrack(string& s, int j, int i, vector<string>& curr, vector<vector<string>>& ans) {

        if (i >= s.size()) {
            if (i == j) ans.push_back(curr);
            return;
        }

        if (isValid(s, j, i)) {
            curr.push_back(s.substr(j, i - j + 1));
            backtrack(s, i + 1, i + 1, curr, ans);
            curr.pop_back();
        }

        backtrack(s, j, i + 1, curr, ans);
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(s, 0, 0, curr, ans);
        return ans;
    }
};