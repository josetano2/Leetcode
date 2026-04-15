class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {

        vector<vector<bool>> visited(x + 1, vector<bool>(y + 1, false));

        queue<pair<int, int>> q;
        q.push({0, 0});

        while(!q.empty()) {
            auto [l, r] = q.front();
            q.pop();
            if(l > x || r > y) continue;
            if(l + r == target) return true;

            if(visited[l][r]) continue;
            visited[l][r] = true;

            if(l == 0) {
                q.push({l + x, r});
            }
            if(r == 0) {
                q.push({l, r + y});
            }

            if(l == x) {
                q.push({0, r});
            }

            if(r == y) {
                q.push({l, 0});
            }

            // spill left to right
            if(r < y) {
                int newL = l, newR = r, rem = 0;
                newR = l + r;
                if(newR > y) {
                    rem = abs(y - newR);
                    newR = y;
                }
                newL = abs(l - newR);
                q.push({newL, newR});
            }

            // spill right to left
            if(l < x) {
                int newL = l, newR = r, rem = 0;
                newL = l + r;
                if(newL > x) {
                    rem = abs(x - newL);
                    newL = x;
                }
                newR = abs(r - newL);
                q.push({newL, newR});
            }
            
        }

        return false;
    }
};