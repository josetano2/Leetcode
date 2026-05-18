class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end(), greater<int>());

        long long ans = 0;
        int limit = nums.size() / 2.0;
        if(nums.size() % 2 == 0) limit--;

        for(int i = 0; i <= limit; i++) ans += pow(nums[i], 2);
        for(int i = limit + 1; i < nums.size(); i++) ans -= pow(nums[i], 2);
        
        return ans;
    }
};