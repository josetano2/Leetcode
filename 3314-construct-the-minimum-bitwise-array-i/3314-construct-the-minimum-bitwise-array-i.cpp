class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            int x = 0;
            while(x < nums[i]) {
                if((x | x + 1) == nums[i]) break;
                x++;
            }
            x = x == nums[i] ? -1 : x;
            ans.push_back(x);
        }

        return ans;
    }
};