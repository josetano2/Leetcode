class Solution {
public:
    int countPermutations(vector<int>& complexity) {

        long long int MOD = 1e09+7;
        for(int i = 1; i < complexity.size(); i++) if(complexity[0] >= complexity[i]) return 0;
        
        long long int ans = 1;
        for (int i = 1; i < complexity.size(); ++i) {
            ans = (ans * i) % MOD;
        }
        return ans;
        
    }
};