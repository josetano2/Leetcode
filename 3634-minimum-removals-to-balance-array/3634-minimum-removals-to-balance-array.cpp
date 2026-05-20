class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> v(n, -1);

        for(int i = 0; i < nums.size(); i++) {
            auto it = upper_bound(nums.begin(), nums.end(), (long long) nums[i] * k);

            if(it != nums.begin()) {
                --it;
                v[i] = it - nums.begin();
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            cout << v[i] << " ";
            ans = min(ans, n - (v[i] - i) - 1);
        }
        return ans == n ? 0 : ans;
    }
};