class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool> skipped(s.size(), false);
        stack<pair<char, int>> stk;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '(' && s[i] != ')') continue;

            if(s[i] == '(') stk.push({s[i], i});
            else if(stk.empty() && s[i] == ')') skipped[i] = true;
            else if(!stk.empty()) stk.pop();
        }

        while(!stk.empty()) {
            auto& [f, i] = stk.top();
            skipped[i] = true;
            stk.pop();
        }
        
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(skipped[i]) continue;
            ans += s[i];
        }
    
        return ans;
    }
};