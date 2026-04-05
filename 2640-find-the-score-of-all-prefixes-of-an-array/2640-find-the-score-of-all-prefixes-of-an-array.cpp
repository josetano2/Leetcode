class Solution {
public:
    
    long long getMax(long long a, long long b) {
        if(a > b) return a;
        return b;
    } 

    vector<long long> findPrefixScore(vector<int>& nums) {
        long long max = INT_MIN;
        vector<long long> ans;
        for(int i = 0; i < nums.size(); i++) {
            max = getMax(max, nums[i]);
            if(i == 0) ans.push_back(nums[i] * 2);
            else {
                long long curr = max + nums[i];
                ans.push_back(curr + ans[i - 1]);
            }
        }
        return ans;
    }
};