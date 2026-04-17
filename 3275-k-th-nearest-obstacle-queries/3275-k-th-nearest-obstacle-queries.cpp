class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        priority_queue<int> pq;
        for(int i = 0; i < queries.size(); i++) {
            int dist = abs(queries[i][0]) + abs(queries[i][1]);
            cout << i << " " << k << endl;

            if(pq.size() < k) {
                pq.push(dist);
                if(pq.size() < k) {
                    ans.push_back(-1); continue;
                }
            }
            else if(pq.size() == k) {
                if(dist < pq.top()) {
                    pq.pop();
                    pq.push(dist);
                }
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};