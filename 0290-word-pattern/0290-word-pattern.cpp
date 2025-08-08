class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> strs;
        unordered_map<char, string> freq;
        unordered_set<string> strOcc;

        string temp = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                temp += s[i];
            }
            else {
                strs.push_back(temp);
                temp = "";
            }
        }
        strs.push_back(temp);

        if(pattern.size() != strs.size()) return false;

        for(int i = 0; i < pattern.size(); i++) {
            if(freq.find(pattern[i]) == freq.end() && strOcc.find(strs[i]) == strOcc.end()) {
                freq[pattern[i]] = strs[i];
                strOcc.insert(strs[i]);
            }
            else {
                if(freq[pattern[i]] != strs[i]) return false;
            }
        }
        
        return true;
    }
};