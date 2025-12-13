class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return false;
        for (char c : s) if (!(isalnum(c) || c == '_')) return false;
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine,vector<bool>& isActive) {
        unordered_map<string, vector<string>> business = {{"restaurant", {}},
                                                          {"pharmacy", {}},
                                                          {"grocery", {}},
                                                          {"electronics", {}}};

        int len = code.size();
        for (int i = 0; i < len; i++) {
            if (isValid(code[i]) && business.find(businessLine[i]) != business.end() && isActive[i]) {
                business[businessLine[i]].push_back(code[i]);
            }
        }  

        vector<string> ans;
        for(auto& [x, y] : business) {
            sort(y.begin(), y.end());
            ans.insert(ans.end(), y.begin(), y.end());
        }

        return ans;
    }
};