class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        vector<int> a1(nums.size(), INT_MIN);
        vector<int> a2(nums.size(), INT_MIN);

        a1[0] = nums[0]; a2[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); i++) a1[i] = max(a1[i - 1], nums[i]);
        for(int i = nums.size() - 2; i >= 0; i--) a2[i] = max(a2[i + 1], nums[i]);

        for(int i = 1; i < nums.size() - 1; i++) {
            ans = max((long long) (a1[i - 1] - nums[i]) * a2[i + 1], ans);
        }

        return ans;
    }
};