class Solution {
public:
    string makeFancyString(string s) {
        
        int len = s.length();
        int repeatingCount = 1;

        string ans = "";
        ans += s[0];
        for(int i = 1; i < len; i++) {
            if(s[i] == s[i - 1]) {
                repeatingCount++;
            }
            else {
                repeatingCount = 1;
            }

            if(repeatingCount < 3) {
                ans += s[i];
            }
        }

        return ans;
    }
};