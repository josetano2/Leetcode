class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1) return 0;

        unordered_map<int, queue<int>> um;
        queue<pair<int, int>> q;
        vector<int> visited(arr.size(), false);

        for(int i = 0; i < arr.size(); i++) if(i != 0) um[arr[i]].push(i);

        q.push({0, arr[0]});
        visited[0] = true;

        int level = 0;
        cout << arr.size() << endl;;
        while(!q.empty()) {
            int s = q.size();
            for(int i = 0; i < s; i++) {
                auto [idx, val] = q.front();
                q.pop();
                
                if(idx == arr.size() - 1) return level;

                if(um.count(arr[idx])) {
                    queue<int>& qt = um[arr[idx]];
                    while(!qt.empty()) {
                        int f = qt.front();
                        qt.pop();

                        if(!visited[f]) {
                            if(f == arr.size() - 1) return level + 1;

                            visited[f] = true;
                            q.push({f, arr[f]});
                        }
                    }

                    um.erase(arr[idx]);
                }

                if(idx + 1 < arr.size() && !visited[idx + 1]) {
                    visited[idx + 1] = true;
                    q.push({idx + 1, arr[idx + 1]});
                    // if(um.find(arr[idx + 1]) != um.end() && um[arr[idx + 1]].size() > 0) um[arr[idx + 1]].pop();
                }

                if(idx - 1 >= 0 && !visited[idx - 1]) {
                    visited[idx - 1] = true;
                    q.push({idx - 1, arr[idx - 1]});
                    // if(um.find(arr[idx - 1]) != um.end() && um[arr[idx - 1]].size() > 0) um[arr[idx - 1]].pop();
                }
            }
            level++;
        }


        return level;
    }
};