class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                ans.push_back(-1); continue;
            }

            int temp = nums[i], count = 0;
            while((temp & 1) == 1) {
                count++;
                temp = temp >> 1;
            }

            int x = nums[i] ^ (1 << (count - 1));
            ans.push_back(x);
        }

        return ans;
        
    }
};