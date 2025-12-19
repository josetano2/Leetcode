class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, ans = 0;
        unordered_map<char, int> freq;

        while(r < s.size() && l < s.size() - 2) {
            freq[s[r]]++;
            if(freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {
                int rem = s.size() - r - 1;
                ans += rem + 1;
                freq[s[l]]--;
                freq[s[r]]--;
                l++;
            }
            else {
                r++;
            }
        }

        return ans;
    }
};