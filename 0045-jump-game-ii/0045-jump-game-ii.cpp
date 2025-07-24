class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();

        if(len == 1) return 0;

        int l = 0, r = 0, ans = 0;

        while(r < len - 1) {
            int highest = 0;
            for(int i = l; i <= r; i++){
                highest = max(nums[i] + i, highest);
            }
            ans++;
            l = r + 1;
            r = highest;
        }

        return ans;   
    }
};