class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, 0);
        vector<int> r(n, 0);

        for(int i = 1; i < n; i++) {
            l[i] = l[i - 1] + nums[i - 1];
            r[n - i - 1] = r[n - i] + nums[n - i];
        }
        for(int i = 0; i < n; i++) {
            l[i] = abs(l[i] - r[i]);
        }
        return l;
    }
};