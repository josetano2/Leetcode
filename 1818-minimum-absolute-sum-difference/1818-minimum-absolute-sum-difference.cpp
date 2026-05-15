class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr = nums1;
        sort(arr.begin(), arr.end());

        vector<int> diff(nums1.size(), INT_MAX);
        int sd = INT_MAX;
        long long tot = 0;
        for(int i = 0; i < nums2.size(); i++) {
            tot += abs(nums1[i] - nums2[i]); 

            int x = nums2[i], d1 = INT_MAX, d2 = INT_MAX;
            auto it = lower_bound(arr.begin(), arr.end(), x);

            if(it != arr.end()) d1 = abs(x - *it);
            if(it != arr.begin()) d2 = abs(x - *prev(it));
            
            diff[i] = min(d1, d2);
        }

        long long ans = tot, MOD = 1e09+7;
        for(int i = 0; i < nums1.size(); i++) ans = min(ans, tot + diff[i] - (abs(nums1[i] - nums2[i])));
        
        return ans % MOD;
    }
};