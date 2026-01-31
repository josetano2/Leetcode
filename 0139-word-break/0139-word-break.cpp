class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> check;
        for(auto s : wordDict) check.insert(s);

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for(int i = 0; i < s.size() + 1; i++) {
            for(int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                cout << sub << endl;
                if(dp[j] && check.count(sub)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};