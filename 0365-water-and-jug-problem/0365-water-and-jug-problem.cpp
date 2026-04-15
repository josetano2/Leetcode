class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {

        vector<vector<bool>> visited(x + 1, vector<bool>(y + 1, false));

        queue<pair<int, int>> q;
        q.push({0, 0});

        while(!q.empty()) {
            auto [l, r] = q.front();
            q.pop();

            if(l + r == target) return true;

            if(visited[l][r]) continue;
            visited[l][r] = true;

            if(l == 0) q.push({x, r});
            if(r == 0) q.push({l, y});
            if(l == x) q.push({0, r});
            if(r == y) q.push({l, 0});
            
            int rem = min(l, y - r);
            q.push({l - rem, r + rem});

            rem = min(x - l, r);
            q.push({l + rem, r - rem});
        }

        return false;
    }
};