class Solution {
public:
    int countTriples(int n) {

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                double x = sqrt(i * i - j * j);
                if(floor(x) == x && x <= n) ans++;
            }
        }

        return ans;
    }
};