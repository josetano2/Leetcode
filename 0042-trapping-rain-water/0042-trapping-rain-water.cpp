class Solution {
public:
    int trap(vector<int>& height) {

        int len = height.size(), maxLeft = height[0], maxRight = height[len - 1], left = 1, right = len - 2, ans = 0;

        while(left <= right){

            if(maxLeft < maxRight){
                if(height[left] > maxLeft){
                    maxLeft = height[left];
                }
                else if(height[left] < maxLeft){
                    ans += maxLeft - height[left];
                }
                left++;
            }
            else{
                if(height[right] > maxRight){
                    maxRight = height[right];
                }
                else if(height[right] < maxRight){
                    ans += maxRight - height[right];
                }
                right--;
            }



        }

        return ans;
    }
};