class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int m = grid.size(), n = grid[0].size();

        unordered_map<int, int> um;
        vector<int> nums;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                um[grid[i][j] % x]++;
                nums.push_back(grid[i][j]);
            }
        }
        
        if(um.size() > 1) return -1;

        sort(nums.begin(), nums.end());
        int target = (nums.size() - 1) / 2, ans = 0;
        cout << target << endl;
        for(int i = 0; i < nums.size(); i++) {
            int diff = (abs(nums[target] - nums[i])) / x;
            ans += diff;
        }

        return ans;
    }
};