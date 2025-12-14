class Solution {
public:
    int numberOfWays(string corridor) {

        vector<pair<int, int>> sPairs;
        long long int MOD = 1e09+7;

        int start = -1;
        for(int i = 0; i < corridor.size(); i++) {
            if(corridor[i] == 'S') {
                if(start == -1) start = i;
                else {
                    sPairs.push_back({start, i});
                    start = -1;
                }
            }
        }
        
        if(start != -1) return 0;
        if(sPairs.size() == 1) return 1;

        long long int ans = sPairs[1].first - sPairs[0].second;
        for(int i = 1; i < sPairs.size() - 1; i++) {
           ans = (ans * (sPairs[i + 1].first - sPairs[i].second)) % MOD;
        }

        return ans;
        
    }
};