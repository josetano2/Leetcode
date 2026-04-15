class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, smallest = INT_MAX;
        for(auto& x : nums) smallest = min(smallest, x);
        for(auto& x : nums) ans += (x - smallest);
        return ans;
    }
};