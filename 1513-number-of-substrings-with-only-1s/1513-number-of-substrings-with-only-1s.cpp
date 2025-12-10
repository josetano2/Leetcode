class Solution {
public:
    int numSub(string s) {
        long long int ans = 0, MOD = 1e09+7;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                int curr = i;
                while(curr < s.size() && s[curr] == '1') {
                    curr++;
                }
                int diff = curr - i;
                ans = (ans + (diff * (diff + 1) / 2)) % MOD;
                i = curr;
            }
        }
        return ans;
    }
};