class Solution {
public:
    int kthFactor(int n, int k) {

        if(n == 1) return 1;
        set<int> factor;

        for(int i = 1; i <= n / 2; i++){
            if(n % i == 0) {
                factor.insert(n / i);
                factor.insert(i);
            }
        }

        int i = 0;
        for(auto& x : factor) {
            if(i == k - 1) return x; 
            i++;
        }

        return -1;
    }
};