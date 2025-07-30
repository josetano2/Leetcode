class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int len = heights.size();
        if(len == 1) return heights[0];

        stack<pair<int, int>> stk;

        // index, height
        stk.push(make_pair(0, heights[0]));
        int maxArea = 0;
        for(int i = 1; i < len; i++) {
            int curr = heights[i];
            int poppedIdx = i;

            // Pop stack
            while(!stk.empty() && stk.top().second > curr) {
                poppedIdx = stk.top().first;
                int tempArea = (i - poppedIdx) * stk.top().second;
                maxArea = max(tempArea, maxArea);
                stk.pop();
            }
            stk.push(make_pair(poppedIdx, curr));
        }

        while(!stk.empty()) {
            int tempArea = (len - stk.top().first) * stk.top().second;
            maxArea = max(tempArea, maxArea);
            stk.pop();
        }

        return maxArea;
    }
};