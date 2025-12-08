class Solution {
public:
    int countTriples(int n) {

        int ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < n; j++) {
                double x = sqrt(i * i + j * j);
                if(floor(x) == x && x <= n) {
                    cout << i * i << " " << j * j << " " << sqrt(i * i + j * j) << endl;
                    ans++;
                }
            }
        }

        return ans;
    }
};