class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;

        for(auto& x : adjacentPairs) {
            int a1 = x[0], a2 = x[1];
            graph[a1].push_back(a2);
            graph[a2].push_back(a1);
        }

        int startPos = 0, prev = 0;
        vector<int> ans;
        for(auto& [x, y] : graph) {
            if(y.size() == 1) {
                startPos = y[0];
                prev = x;
                ans.push_back(x);
                break;
            }
        }

        while(graph[startPos].size() != 1) {
            auto y = graph[startPos];
            int nextStep = y[0] == prev ? y[1] : y[0];
            ans.push_back(startPos);
            prev = startPos;
            startPos = nextStep;
        }

        ans.push_back(startPos);
        return ans;
    }
};