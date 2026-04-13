class Solution {
public:
    int longestContinuousSubstring(string s) {

        int l = 0, r = 1, ans = 1;

        while(r < s.size()) {
            if(s[r] != s[r - 1] + 1) {
                ans = max(ans, r - l);
                l = r;
            }
            r++;
        }
        return max(ans, r - l);
        
    }
};