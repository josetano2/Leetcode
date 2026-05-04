class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());

        int currMax = INT_MIN, ans = INT_MIN;
        for(int i = 1; i <= tasks.size(); i++) {
            if(i % 4 == 0) {
                ans = max(ans, currMax);
            }
            else {
                currMax = max(currMax, processorTime[(i - 1) / 4] + tasks[i - 1]);
            }
        }

        return ans;
    }
};