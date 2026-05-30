class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), tot = (n * (n + 1)) / 2;

        for(auto& x : nums) tot -= x;
        return tot;
    }
};