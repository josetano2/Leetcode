class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int tot = 1, len = nums.size(), zeroCounter = 0;


        for(int i = 0; i < len; i++){
            if(nums[i] != 0){
                tot *= nums[i];
            }
            else{
                zeroCounter++;
            }
        }

        // cout << tot;

        for(int i = 0; i < len; i++){
            if(zeroCounter > 1 || (zeroCounter >= 1 && nums[i] != 0)){
                ans.push_back(0);
            }
            // nums[i] = 0
            // 
            else if(zeroCounter == 1 && nums[i] == 0){
                ans.push_back(tot);
            }
            else{
                ans.push_back(tot/nums[i]);
            }
        }

        return ans;
    }
};