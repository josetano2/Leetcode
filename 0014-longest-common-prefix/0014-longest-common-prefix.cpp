class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        unordered_map<string, int> freq;

        for(auto str : strs) {
            string temp = "";
            int len = str.length();

            for(int i = 0; i < len; i++) {
                temp += str[i];
                freq[temp]++;
            }
        }

        string ans = "";
        for(auto x : freq) {
            if(x.second == strs.size() && ans.length() < x.first.length()) {
                ans = x.first;
            }
        }

        return ans;
    }
};