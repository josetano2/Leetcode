class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0, gap = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '1') {
                count += gap;
                cout << s[i] << " " << gap << " " << count << endl;
            }
            else {
                gap++;
            }
        }
        return count;
    }
};