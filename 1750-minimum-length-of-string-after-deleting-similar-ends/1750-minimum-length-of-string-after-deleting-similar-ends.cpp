class Solution {
public:
    int minimumLength(string s) {

        int l = 0, r = s.size() - 1;

        while(l < r && s[l] == s[r]) {
            while(l + 1 < s.size() && s[l] == s[l + 1]) l++;
            while(r - 1 >= 0 && s[r] == s[r - 1]) r--;

            l++; r--;
        }
        cout << l << " " << r << endl;
        
        return l <= r ? r - l + 1 : 0;
    }
};