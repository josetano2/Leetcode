class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1000 + 2, 0);
        for(int i = 0; i < trips.size(); i++) {
            int from = trips[i][1], to = trips[i][2], pss = trips[i][0];
            diff[from] += pss, diff[to] -= pss;
        }

        int curr = 0;
        for(int i = 0; i <= 1000; i++) {
            curr += diff[i];
            if(curr > capacity) return false;
        }
        return true;
    }
};