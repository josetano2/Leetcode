class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n), s(n);

        p[0] = 1;
        s[n - 1] = 1;
        for(int i = 1; i < n; i++) {
            p[i] = p[i - 1] * nums[i - 1];
            s[n - i - 1] = s[n - i] * nums[n - i];
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) ans.push_back(p[i] * s[i]);
        return ans;
    }
};