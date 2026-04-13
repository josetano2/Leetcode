class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 2, 0);
        vector<int> ans;
        for(int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0], last =  bookings[i][1], seats = bookings[i][2];
            diff[first] += seats; diff[last + 1] -= seats;
        }

        int curr = 0;
        for(int i = 1; i <= n; i++) {
            curr += diff[i];
            ans.push_back(curr);
        }
        return ans;
    }
};