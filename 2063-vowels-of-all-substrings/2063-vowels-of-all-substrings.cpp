class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
    }

    long long countVowels(string word) {
        int n = word.size();
        vector<long long> dp(n + 1, 0);
        
        long long tot = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(isVowel(word[i])) dp[i] = n - i + dp[i + 1];
            else dp[i] = dp[i + 1];

            tot += dp[i];
        }
        return tot;
    }
    
};