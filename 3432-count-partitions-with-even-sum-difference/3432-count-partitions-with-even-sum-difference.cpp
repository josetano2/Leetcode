class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tot = 0;
        for(auto& x : nums) tot += x;
        return (tot ^ 1) == (tot + 1) ? nums.size() - 1 : 0;
    }
};