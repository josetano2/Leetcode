class Solution {
public:
    string longestPalindrome(string s) {

        string ans = "";
        for(int i = 0; i < s.length(); i++) {

            int l = i, r = i;
            string temp = "";

            // odd
            while(l >= 0 && r < s.length() && s[l] == s[r]) {

                if(temp.length() == 0) {
                    temp += s[l];
                }
                else {
                    temp.push_back(s[r]);
                    temp.insert(temp.begin(), s[l]);
                }
                r++;
                l--;
            }

            if(temp.length() > ans.length()) ans = temp;

            l = i, r = i + 1;
            temp = "";
            
            // even
            while(l >= 0 && r < s.length() && s[l] == s[r]) {
                temp.push_back(s[r]);
                temp.insert(temp.begin(), s[l]);
                r++;
                l--;
            }
            
            if(temp.length() > ans.length()) ans = temp;
        }

        return ans;
    }
};