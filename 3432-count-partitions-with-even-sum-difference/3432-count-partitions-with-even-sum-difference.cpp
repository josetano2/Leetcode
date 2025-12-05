class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> prefixSum(nums.size(), 0);

        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) prefixSum[i] = prefixSum[i - 1] + nums[i];

        int total = prefixSum[nums.size() - 1], l = prefixSum[0], r = 0, ans = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            r = total - l;
            int diff = l - r;
            cout << diff << endl;
            if((diff ^ 1) == diff + 1) {
                ans++;
            }
            l += prefixSum[i + 1];
            r -= prefixSum[i + 1];
        }
        
        return ans;
    }
};