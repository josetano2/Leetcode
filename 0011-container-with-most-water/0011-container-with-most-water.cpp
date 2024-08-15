class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();

        int left = 0, right = len - 1, maxVol = -1;
        
        while(left < right){
            int minHeight = height[left] < height[right] ? height[left] : height[right];
            int volume = (right - left) * minHeight;
            if(volume > maxVol){
                cout << height[left] << " " << height[right] << endl;
                maxVol = volume;
            }
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxVol;
    }
};