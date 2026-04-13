class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for(int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0], last =  bookings[i][1], seats = bookings[i][2];
            for(int j = first - 1; j < last; j++) ans[j] += seats;
        }

        return ans;
    }
};