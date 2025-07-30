class Solution {
public:
    int maxArea(vector<int>& height) {

        int len = height.size();

        int l = 0, r = height.size() - 1, area = -1;

        while(l < r) {
            int curr = min(height[l], height[r]);
            cout << r << " " << l << endl;
            area = max(area, curr * (r - l));

            if(height[l] < height[r]) l++;
            else r++;
        }

        return area;
    }
};