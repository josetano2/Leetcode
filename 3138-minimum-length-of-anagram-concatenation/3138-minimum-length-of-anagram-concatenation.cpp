class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();

        for(int k = 1; k <= n; k++) {
            if(n % k != 0) continue;

            bool flag = true;
            vector<int> left(26, 0);
            for(int i = 0; i < k; i++) left[s[i] - 'a']++;
            for(int i = k; i < n; i += k) {
                vector<int> right(26, 0);
                for(int j = i; j < i + k; j++) right[s[j] - 'a']++;
                if(left != right) {
                    flag = false; break;
                }
            }

            if(flag) return k;
        }
        return n;
    }
};