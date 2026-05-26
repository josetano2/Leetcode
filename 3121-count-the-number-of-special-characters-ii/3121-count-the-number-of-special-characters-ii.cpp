class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> s(26, false);
        vector<bool> b(26, false);
        
        for(auto& w : word) {
            if(w >= 'a' && w <= 'z') {
                if(b[w - 'a']) s[w - 'a'] = false;
                else s[w - 'a'] = true;
            }
            else b[w - 'A'] = true;
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) if(s[i] && b[i]) ans++;
        return ans;
    }
};