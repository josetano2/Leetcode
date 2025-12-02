class Solution {
public:
    vector<int> tickets = {1, 7, 30};
    int dp(vector<int>& cache, vector<int>& days, vector<int>& costs, int idx) {
        if (idx >= days.size()){
            return 0;
        }
        if (cache[idx] != -1) {
            return cache[idx];
        }
            

        int res = INT_MAX;
        for (int i = 0; i < tickets.size(); i++) {
            // 1 + 7 - 1 = 7
            int nextDay = days[idx] + tickets[i] - 1;

            // search days
            int j = idx;
            while (j < days.size() && days[j] <= days[idx] + tickets[i] - 1) {
                j++;
            }

            int temp = dp(cache, days, costs, j);
            res = min(res, costs[i] + temp);
        }
        cache[idx] = res;
        return cache[idx];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        vector<int> cache(days.size(), -1);
        int ans = dp(cache, days, costs, 0);
        return ans;
    }
};