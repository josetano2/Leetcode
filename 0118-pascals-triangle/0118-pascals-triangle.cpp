class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1; i <= numRows; i++) {
            vector<int> temp;
            for(int j = 0; j < i; j++) {
                if(j == 0 || j == i - 1) {
                    temp.push_back(1);
                }
                else {
                    int curr = ans[i - 2][j - 1] + ans[i - 2][j];
                    temp.push_back(curr);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};