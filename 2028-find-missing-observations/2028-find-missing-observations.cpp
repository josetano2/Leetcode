class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int total = 0, m = rolls.size(), res = 0;

        for(auto x : rolls){
            total += x;
        }

        res = mean * (n + m) - total;

        int curr = res / n;

        if(curr > 6 || curr < 1 || res > 6 * n){
            return {};
        }

        vector<int> combinations(n, curr);
        int rest = res % n;
        cout << rest;

        for(int i = 0; i < rest; i++){
            combinations[i]++;
        }
        
        return combinations;
    }
};