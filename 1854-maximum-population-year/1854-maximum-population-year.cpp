class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        unordered_map<int, int> population;
        pair<int, int> ans = {-1, -1};
        for(auto& x : logs) {
            int diff = x[1] - x[0];
            int year = x[0];
            for(int i = 0; i < diff; i++) {
                population[year]++;

                if(population[year] > ans.second) {
                    ans.first = year;
                    ans.second = population[year];
                }

                year++;
            }
        }

        for(auto& [x, y] : population) if(y == ans.second) ans.first = min(x, ans.first);
        
        return ans.first;
    }
};