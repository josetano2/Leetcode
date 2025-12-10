class Solution {
public:
    int numSub(string s) {

        vector<long long int> cache(100000, 0);
        cache[0] = 1;
        long long int ans = 0, MOD = 1e09+7;
        
        for(int i = 1; i < 100000; i++) cache[i] = (cache[i - 1] + i + 1) % MOD;

        cout << endl;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                int curr = i;
                while(curr < s.size() && s[curr] == '1') {
                    curr++;
                }
                int diff = curr - i;
                ans = (ans + cache[diff - 1]) % MOD;
                i = curr;
            }
        }
        

        return ans;
    }
};