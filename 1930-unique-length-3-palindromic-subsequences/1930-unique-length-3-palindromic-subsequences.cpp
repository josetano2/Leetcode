class Solution {
public:
    int countPalindromicSubsequence(string s) {

        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) first[idx] = i;
            last[idx] = i;
        }

        for (int i = 0; i < 26; i++) {
            if(first[i] != -1 && last[i] != first[i]) {
                unordered_set<char> seen;
                for(int j = first[i] + 1; j < last[i]; j++) seen.insert(s[j]);
                count += seen.size();
            }
        }

        return count;
    }
};