class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.empty()) return 0;
        sort(tokens.begin(), tokens.end());
        if(tokens[0] > power) return 0;

        int l = 0, r = tokens.size() - 1, ans = INT_MIN, c = 0, o = power;
        while(l <= r) {
            cout << ans << " " << c << endl;
            if(power >= tokens[l]) {
                c++;
                power -= tokens[l];
                l++;
            }
            else {
                if(c > 0) ans = max(c, ans);
                c--;
                power += tokens[r];
                r--;
            }
        }

        cout << ans << " " << c << endl;
        return max(c, ans);
    }   
};