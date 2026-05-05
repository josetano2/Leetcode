class Solution {
public:

    bool canForm(vector<int>& nums, int p, int x) {
        int count = 0, i = 0;
        while(i < nums.size() - 1) {
            if(nums[i + 1] - nums[i] <= x) {
                count++;
                i += 2;
            }
            else {
                i += 1;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.back() - nums.front(), mid = 0;
        while(l < r) {
            mid = l + (r - l) / 2;
            cout << l << " " << mid << " " << r << endl;

            if(canForm(nums, p, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};