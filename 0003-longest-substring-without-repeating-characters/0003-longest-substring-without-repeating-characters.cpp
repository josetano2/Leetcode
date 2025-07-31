class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0, r = 0, ans = 0, len = s.size();
        unordered_set<char> uSet;

        while(r < len) {
            if(!uSet.count(s[r])) {
                uSet.insert(s[r]);
                r++;
            }
            else {
                ans = max(ans, r - l);
                while(uSet.count(s[r])) {
                    uSet.erase(s[l]);
                    l++;
                }
            }
        }

        cout << r << " " << l << endl;
        ans = max(ans, r - l);
        return ans;

    }
};