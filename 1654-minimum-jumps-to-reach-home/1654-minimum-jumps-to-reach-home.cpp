class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> s(forbidden.begin(), forbidden.end());
        unordered_set<int> visited;

        int ans = 0, limit = 100000;

        // true = forward, false = backward
        queue<pair<int, bool>> q; q.push({0, true});
        visited.insert(2 * 0 + 1);
        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                if(curr.first == x) return ans;

                int next = curr.first + a, prev = curr.first - b;
                if(!s.count(next) && !visited.count(2 * next + 1) && next <= limit) {
                    q.push({next, true}); visited.insert(2 * next + 1);
                }
                if(!s.count(prev) && !visited.count(2 * prev) && prev >= 0 && curr.second) {
                    q.push({prev, false}); visited.insert(2 * prev);
                }
            }

            ans++;
        }
        
        return -1;
    }
};