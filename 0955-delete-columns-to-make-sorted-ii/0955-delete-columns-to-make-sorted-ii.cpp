class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int ans = 0, sl = strs[0].size(), len = strs.size();

        vector<bool> settled(len - 1, false);
        for(int s = 0; s < sl; s++) {
            bool shouldDelete = false;
            for(int i = 0; i < len - 1; i++) {
                if(settled[i]) continue;
                if(strs[i][s] > strs[i + 1][s]) {
                    shouldDelete = true;
                    break;
                }
            }

            if(shouldDelete) ans++;
            else {
                for(int i = 0; i < len - 1; i++) {
                    if(strs[i][s] < strs[i + 1][s]) {
                        settled[i] = true;
                    }
                }
            }
        }

        return ans;
    }
};