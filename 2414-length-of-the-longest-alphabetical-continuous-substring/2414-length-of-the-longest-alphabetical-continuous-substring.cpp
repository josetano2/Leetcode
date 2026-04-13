class Solution {
public:
    int longestContinuousSubstring(string s) {

        int l = 0, r = 0, curr = 'a', ans = INT_MIN;

        while(r < s.size()) {
            if(l == r) {
                curr = s[r]; r++; continue;
            }

            if(s[r] == curr + 1) {
                curr++;
                r++;
            }
            else {
                ans = max(ans, r - l);
                l = r;
            }
        }
        return max(ans, r - l);
        
    }
};