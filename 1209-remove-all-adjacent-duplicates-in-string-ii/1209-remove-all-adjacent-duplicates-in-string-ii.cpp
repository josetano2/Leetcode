class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;

        for(auto& c : s) {
            if(!stk.empty() && stk.top().first == c) {
                stk.top().second++;
                if(stk.top().second == k) {
                    stk.pop();
                }
            }
            else {
                stk.push({c, 1});
            }
        }

        string ans = "";
        while(!stk.empty()) {
            auto& [c, count] = stk.top();
            stk.pop();
            ans.append(count, c);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};