class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        vector<int> diff(101, 0);

        for(auto& log : logs) {
            diff[log[0] - 1950]++;
            diff[log[1] - 1950]--;
        }

        int biggestPopulation = INT_MIN, currPopulation = 0, earliestYear = INT_MIN;
        for(int i = 0; i < 101; i++) {
            currPopulation += diff[i];
            if(currPopulation > biggestPopulation) {
                biggestPopulation = currPopulation;
                earliestYear = i + 1950;
            }
        }
        return earliestYear;
    }
};