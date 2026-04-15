class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;

        for (auto& pair : adjacentPairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int curr = 0, prev = -1;
        vector<int> result;

        for (auto& [node, neighbors] : graph) {
            if (neighbors.size() == 1) {
                prev = node;
                curr = neighbors[0];
                result.push_back(node);
                break;
            }
        }

        while (graph[curr].size() != 1) {
            auto& neighbors = graph[curr];
            int next = neighbors[0] == prev ? neighbors[1] : neighbors[0];
            result.push_back(curr);
            prev = curr;
            curr = next;
        }

        result.push_back(curr);
        return result;
    }
};