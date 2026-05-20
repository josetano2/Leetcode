class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        long long ans = -1;

        for(int i = 0; i < n; i++) {
            stack<int> stk;
            long long c = heights[i];
            vector<int> h = heights;
            for(int j = i - 1; j >= 0; j--) {
                if(j == i - 1 && h[j] > heights[i]) h[j] = heights[i];

                if(stk.empty() || (!stk.empty() && stk.top() > h[j])) stk.push(h[j]);
                else if(!stk.empty() && stk.top() < h[j]) h[j] = stk.top();
                c += h[j];
            }
            stk = {};
            for(int j = i + 1; j < n; j++) {
                if(j == i + 1 && h[j] > heights[i]) h[j] = heights[i];

                if(stk.empty() || (!stk.empty() && stk.top() > h[j])) stk.push(h[j]);
                else if(!stk.empty() && stk.top() < h[j]) h[j] = stk.top();
                c += h[j];
            }
            ans = max(c, ans);
        }

        return ans;
    }
};