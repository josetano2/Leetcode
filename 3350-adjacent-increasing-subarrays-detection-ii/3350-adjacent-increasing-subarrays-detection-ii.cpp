class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        int prevL = 0, l = 0, ans = 1, n = nums.size(), count = 0;
        bool flag = false;
        for(int i = 1; i < n; i++) {
            // cout << prevL << " " << l << " " << endl;
            if(nums[i] <= nums[i - 1]) {
                if(count >= 1) {
                    cout << n << " " << prevL << " " << l << " " << count << endl;
                    ans = max({ans, min(l - prevL, i - l), (l - prevL) / 2});
                    prevL = l;
                }
                l = i;
                count++;
            }
        }

        cout << n << " " << prevL << " " << l << " " << count << endl;
        if(count >= 1) ans = max({ans, min(l - prevL, n - l), (l - prevL) / 2});
        return max(ans, (n - l) / 2);
    }
};