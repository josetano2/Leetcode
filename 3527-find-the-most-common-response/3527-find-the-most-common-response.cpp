class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        
        unordered_map<string, int> um;

        for(auto& rs : responses) {
            unordered_set<string> us;

            for(auto& r : rs) us.insert(r);
            for(auto& s : us) um[s]++;
        }

        string ans = "";
        int val = INT_MIN;

        for(auto& [x, y] : um) {
            if(y > val) {
                ans = x;
                val = y;
            }
            else if(y == val) {
                if(x < ans) ans = x;
            }
        }

        return ans;
    }
};