class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int ans = 0, sLen = strs[0].size(), len = strs.size();

        for(int i = 0; i < sLen; i++) {
            for(int j = 0; j < len - 1; j++) {
                if(strs[j][i] > strs[j + 1][i]) {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};