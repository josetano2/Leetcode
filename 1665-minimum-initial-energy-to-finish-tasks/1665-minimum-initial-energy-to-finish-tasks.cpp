class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return a[1] - a[0] > b[1] - b[0];
        });

        int min = 0, max = 0;
        for(auto& t : tasks) {
            min += t[0]; max += t[1];
        }

        while(min < max) {
            int mid = min + (max - min) / 2;
            bool isValid = true;
            int temp = mid;
            for(auto& t : tasks) {
                if(temp >= t[1]) temp -= t[0];
                else {
                    isValid = false; break;
                }
            }

            if(isValid) max = mid;
            else min = mid + 1;
        }
        return min;
    }
};