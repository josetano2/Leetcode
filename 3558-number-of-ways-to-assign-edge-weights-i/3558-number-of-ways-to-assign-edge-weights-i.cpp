class Solution {
public:
    long long assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_set<int> us;
        unordered_map<int, vector<int>> um;
        long long MOD = 1e09 + 7;

        for(auto& e : edges) {
            us.insert(e[1]);
            um[e[0]].push_back(e[1]);
        }

        int root = -1;
        for(auto& e : edges) {
            if(!us.count(e[0])) {
                root = e[0];
                break;
            }
        }

        queue<int> q;
        q.push(root);
        int depth = 0, ans = 1;

        while(!q.empty()) {
            int qs = q.size();

            for(int i = 0; i < qs; i++) {
                int t = q.front();
                q.pop();

                for(auto& x : um[t]) q.push(x);
            }
            depth++;
        }

        for(int i = 0; i < depth - 2; i++) {
            ans = ans * 2 % MOD;
        }

        return ans; 
    }
};