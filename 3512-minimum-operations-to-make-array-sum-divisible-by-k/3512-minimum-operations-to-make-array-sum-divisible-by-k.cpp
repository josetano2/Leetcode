class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int tot = 0;
        for(auto& x : nums) tot += x;
        return tot % k;
    }
};