class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
    }

    long long countVowels(string word) {
        int n = word.size();        
        long long tot = 0, last = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(isVowel(word[i])) last += n - i;
            tot += last;
        }
        return tot;
    }
    
};