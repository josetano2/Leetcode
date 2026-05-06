class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> rev(n, vector<char>(m, '.'));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rev[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        
        for(int i = 0; i < m; i++) {
            pair<int, int> e = {-1, -1};
            for(int j = n - 1; j >= 0; j--) {
                if(rev[j][i] == '.' && e.second == -1) {
                    e = {i, j};
                }

                if(rev[j][i] == '*') {
                    e = {-1, -1};
                }

                if(rev[j][i] == '#' && e.first != -1) {
                    rev[e.second][e.first] = '#';
                    rev[j][i] = '.';
                    e = {i, e.second - 1};
                }
            }
        }

        return rev;
    }
};