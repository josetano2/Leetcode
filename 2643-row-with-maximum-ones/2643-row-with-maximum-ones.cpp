class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ans = 0, idx = 0;
        for(int i = 0; i < mat.size(); i++) {
            int curr = 0;

            for(auto& x : mat[i]) {
                if(x == 1) curr++;
            }

            if(curr > ans) {
                ans = curr;
                idx = i;
            }
        }

        return {idx, ans};
    }
};