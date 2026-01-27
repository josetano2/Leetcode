class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int, int>> graph;
        for(auto& x : edges) {
            int u = x[0], v = x[1], w = x[2];
            if(graph[u].find(v) != graph[u].end()) graph[u][v] = min(graph[u][v], w);
            else graph[u][v] = w;

            if(graph[v].find(u) != graph[u].end()) graph[v][u] = min(graph[v][u], w * 2);
            else graph[v][u] = w * 2;
        }

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currNode, currCost] = pq.top();
            pq.pop();

            if (visited[currNode]) continue;

            visited[currNode] = true;

            if (currNode == n - 1) return currCost;

            for (auto [v, w] : graph[currNode]) {
                int newCost = currCost + w;

                if (newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({v, newCost});
                }
            }
        }

        return -1;
    }
};