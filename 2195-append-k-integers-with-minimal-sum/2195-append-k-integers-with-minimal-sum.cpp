class Solution {
public:
    long long arit(long long n) {
        return n * (n + 1) / 2;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long curr = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(curr == nums[i] || nums[i] - curr == 1) {
                curr = nums[i];
                continue;
            }

            long long diff = nums[i] - curr - 1, l = arit(curr), r = 0;
            if(k - diff >= 0) r = arit(nums[i] - 1);
            else r = arit(curr + k);

            ans += (r - l);
            k -= diff;
            curr = nums[i];

            if(k <= 0) return ans;
        }

        if(k > 0) {
            long long res = arit(nums[nums.size() - 1] + k), t = arit(nums[nums.size() - 1]);
            ans += (res - t);
        }
        return ans;
    }
};