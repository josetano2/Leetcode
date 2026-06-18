class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans = events[0][0], diff = events[0][1];
        for(int i = 0; i < events.size() - 1; i++) {
            if(events[i + 1][1] - events[i][1] > diff) {
                diff = events[i + 1][1] - events[i][1];
                ans = events[i + 1][0];
            }
            else if(events[i + 1][1] - events[i][1] == diff) ans = min(ans, events[i + 1][0]);
        }
        return ans;
    }
};