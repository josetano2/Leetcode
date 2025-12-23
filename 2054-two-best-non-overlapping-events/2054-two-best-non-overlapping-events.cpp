class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        
        vector<int> dp(events.size(), 0);
        vector<int> bestSingle(events.size(), INT_MIN);
        dp[0] = events[0][2];
        bestSingle[0] = events[0][2];
        for(int i = 1; i < events.size(); i++) {
            int start = events[i][0], end = events[i][1], val = events[i][2];

            int l = 0, r = i - 1, res = -1;
            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(start > events[mid][1]) {
                    res = mid;
                    l = mid + 1;
                }

                else {
                    r = mid - 1;
                }
            }
            
            bestSingle[i] = max(bestSingle[i - 1], val);
            dp[i] = max(dp[i - 1], res == -1 ? val : bestSingle[res] + val);
        }

        return dp[events.size() - 1];
    }
};