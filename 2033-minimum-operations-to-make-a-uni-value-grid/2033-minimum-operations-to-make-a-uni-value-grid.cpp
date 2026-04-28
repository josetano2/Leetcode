class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int m = grid.size(), n = grid[0].size();

        vector<int> nums;
        int rem = grid[0][0] % x;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] % x != rem) return -1;
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        int target = (nums.size() - 1) / 2, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int diff = (abs(nums[target] - nums[i])) / x;
            ans += diff;
        }

        return ans;
    }
};