class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> freq;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]].push_back(i);
            if(freq[nums[i]].size() == 3) {
                vector<int>& curr = freq[nums[i]];
                int currDist = abs(curr[0] - curr[1]) + abs(curr[1] - curr[2]) + abs(curr[2] - curr[0]);
                ans = min(ans, currDist);
                curr.erase(curr.begin());
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};