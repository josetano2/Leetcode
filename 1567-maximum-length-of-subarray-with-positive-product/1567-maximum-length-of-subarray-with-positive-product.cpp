class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int prevPos = 0, prevNeg = 0, currPos = 0, currNeg = 0;

        if(nums[0] > 0){
            prevPos = 1;
            prevNeg = 0;
        }
        else if(nums[0] < 0) {
            prevPos = 0;
            prevNeg = 1;
        }
        else {
            prevPos = 0;
            prevNeg = 0;
        }


        int ans = prevPos;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > 0) {
                currPos = prevPos + 1;
                currNeg = prevNeg > 0 ? prevNeg + 1 : 0;
            }
            else if(nums[i] < 0) {
                currNeg = prevPos + 1;
                currPos = prevNeg > 0 ? prevNeg + 1 : 0;
            }
            else {
                currPos = 0;
                currNeg = 0;
            }
            ans = max(ans, currPos);
            prevPos = currPos;
            prevNeg = currNeg;
            
        }
        return ans;
        
    }
};