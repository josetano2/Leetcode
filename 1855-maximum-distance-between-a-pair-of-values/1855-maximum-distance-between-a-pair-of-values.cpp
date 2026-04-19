class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MIN;
        for(int i = 0; i < nums1.size(); i++) {
            int l = i, r = nums2.size() - 1, mid = 0, curr = nums1[i];
            while(l <= r) {
                mid = l + (r - l) / 2;
                if(curr <= nums2[mid]) l = mid + 1;
                else r = mid - 1;
            }
            if(i <= r) ans = max(ans, r - i);
        }
        return ans == INT_MIN ? 0 : ans;
    }
};