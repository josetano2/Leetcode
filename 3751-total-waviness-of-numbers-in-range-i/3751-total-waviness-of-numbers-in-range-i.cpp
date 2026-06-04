class Solution {
public:
    int totalWaviness(int num1, int num2) {
        
        int ans = 0;
        for(int i = num1; i <= num2; i++) {
            if(i < 100) continue;

            string s = to_string(i);
            int len = s.size();

            for(int i = 1; i <= len - 2; i++) {
                int prev = s[i - 1] - '0', curr = s[i] - '0', next = s[i + 1] - '0';
                if((curr > prev && curr > next) || (curr < prev && curr < next)) ans++;
            }
        }
        return ans;
    }
};