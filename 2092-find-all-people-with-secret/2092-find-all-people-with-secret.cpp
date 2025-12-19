class Solution {
public:

    void dfs(int node, unordered_set<int>& secret, unordered_map<int, vector<int>>& graph) {
        for(auto& x : graph[node]) {
            if(secret.find(x) == secret.end()) {
                secret.insert(x);
                dfs(x, secret, graph);
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<unordered_map<int, vector<int>>> graph;

        int currTime = -1, k = -1;
        for (int i = 0; i < meetings.size(); i++) {
            int x = meetings[i][0], y = meetings[i][1], time = meetings[i][2];
            if (time != currTime) {
                currTime = time;
                graph.push_back({});
                k++;
            }

            graph[k][x].push_back(y);
            graph[k][y].push_back(x);
        }
        unordered_set<int> secret;
        secret.insert(0);
        secret.insert(firstPerson);

        for (int i = 0; i < graph.size(); i++) {
            for (const auto& [node, neighbors] : graph[i]) {
                if (secret.find(node) != secret.end()) {
                    dfs(node, secret, graph[i]);
                }
            }
        }
        return vector<int>(secret.begin(), secret.end());
    }
};