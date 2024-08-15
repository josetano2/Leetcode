class Solution {
public:
    bool isAnagram(string s, string t) {

        int sLen = s.length();
        int tLen = t.length();

        int charArr[26] = {0};

        for (int i = 0; i < sLen; i++) {
            charArr[s[i] - 'a']++;
        }

        for (int i = 0; i < tLen; i++) {
            charArr[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (charArr[i] != 0) {
                return false;
            }
        }

        return true;
    }
};