class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int, set<int>> hashY;
        unordered_map<int, set<int>> hashX;

        for (auto& coordinates : buildings) {
            int x = coordinates[0], y = coordinates[1];

            hashX[x].insert(y);
            hashY[y].insert(x);
        }

        int ans = 0;
        for (auto& coordinates : buildings) {
            int x = coordinates[0], y = coordinates[1];

            if (x < *hashY[y].rbegin() && x > *hashY[y].begin() &&
                y < *hashX[x].rbegin() && y > *hashX[x].begin())
                ans++;
        }

        return ans;
    }
};