class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> times;

        for(auto x : timePoints) {
            string hours = string(1, x[0]) + string(1, x[1]), minutes = string(1, x[3]) + string(1, x[4]);
            times.push_back(stoi(hours) * 60 + stoi(minutes));
        }

        sort(times.begin(), times.end());
        int len = times.size(), ans = INT_MAX;

        for(int i = 0; i < len; i++){
            int diff = i != len - 1 ? abs(times[i] - times[i + 1]) : abs(times[i] - times[0]);
            if(diff > 720) diff = 1440 - diff;
            ans = min(ans, diff);
        }

        return ans;

    }
};
