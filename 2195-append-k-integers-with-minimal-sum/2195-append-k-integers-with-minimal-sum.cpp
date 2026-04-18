class Solution {
public:
    long long getMax(int a, int b) {
        return a > b ? a : b;
    }

    long long arit(long long n) {
        return n * (n + 1) / 2;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long curr = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(k <= 0) return ans;
            if(curr == nums[i] || nums[i] - curr == 1) {
                curr = nums[i];
                continue;
            }

            long long diff = nums[i] - curr - 1, l = 0, r = 0;
            if(k - diff >= 0) l = arit(curr), r = arit(nums[i] - 1);
            else l = arit(curr), r = arit(curr + k);
            cout << curr << " " << nums[i] << " " << l << " " << r << endl;

            ans += (r - l);
            k -= diff;
            curr = nums[i];
        }

        if(k > 0) {
            long long res = arit(nums[nums.size() - 1] + k), t = arit(nums[nums.size() - 1]);
            ans += (res - t);
        }
        return ans;
    }
};