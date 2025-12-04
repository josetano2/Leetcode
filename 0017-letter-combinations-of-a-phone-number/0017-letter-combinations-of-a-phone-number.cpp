class Solution {
public:
    unordered_map<string, vector<string>> numbers;

    void backtrack(int idx, string curr, string s, vector<string>& ans) {

        if (curr.size() == s.size()) {
            ans.push_back(curr);
            return;
        }

        string temp(1, s[idx]);
        for (int i = 0; i < numbers[temp].size(); i++) {
            curr += numbers[temp][i];
            cout << curr << endl;
            backtrack(idx + 1, curr, s, ans);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        numbers["2"] = {"a", "b", "c"};
        numbers["3"] = {"d", "e", "f"};
        numbers["4"] = {"g", "h", "i"};
        numbers["5"] = {"j", "k", "l"};
        numbers["6"] = {"m", "n", "o"};
        numbers["7"] = {"p", "q", "r", "s"};
        numbers["8"] = {"t", "u", "v"};
        numbers["9"] = {"w", "x", "y", "z"};

        vector<string> ans;
        backtrack(0, "", digits, ans);
        return ans;
    }
};