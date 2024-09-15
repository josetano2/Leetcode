class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowels ={
            {'a', 1},
            {'e', 2},
            {'i', 4},
            {'o', 8},
            {'u', 16}
        };

        unordered_map<int, int> savedPrefix;
        for (int i = 0; i < 32; ++i) savedPrefix[i] = -1; 

        int ans = 0, currPrefix = 0, len = s.length();

        for(int i = 0; i < len; i++){
            if(vowels[s[i]] != 0) currPrefix ^= vowels[s[i]];

            if(savedPrefix[currPrefix] != -1 || currPrefix == 0){
                int currLen = i - savedPrefix[currPrefix];
                ans = max(currLen, ans);
            }
            else{
                savedPrefix[currPrefix] = i;
            }
        }

        return ans;
    }

};