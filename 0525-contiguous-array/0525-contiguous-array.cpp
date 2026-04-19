class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> prefixArr(nums.size(), 0);

        prefixArr[0] = nums[0] == 0 ? -1 : 1;
        for(int i = 1; i < nums.size(); i++) prefixArr[i] = prefixArr[i - 1] + (nums[i] == 0 ? -1 : 1);
    
        unordered_map<int, vector<int>> um;
        for(int i = 0; i < prefixArr.size(); i++) um[prefixArr[i]].push_back(i);
        
        int ans = INT_MIN;
        for(auto& [x, y] : um) {
            if(x == 0) ans = max(ans, y[y.size() - 1] + 1);
            else if(y.size() >= 2) ans = max(ans, y[y.size() - 1] - y[0]);
        }
        return ans == INT_MIN ? 0 : ans;
    }
};