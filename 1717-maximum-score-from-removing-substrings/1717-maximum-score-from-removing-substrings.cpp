class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int len = s.length(), ans = 0;
        stack<char> stk;

        int bNum = x > y ? x : y;
        int sNum = x < y ? x : y;
        char fChar = x > y ? 'a' : 'b';
        char sChar = x > y ? 'b' : 'a';

        for (int i = 0; i < len; i++) {
            if (stk.empty()) {
                stk.push(s[i]);
                continue;
            }

            if (stk.top() == fChar && s[i] == sChar) {
                ans += bNum;
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }

        string newS = "";
        while(!stk.empty()) {
            newS += stk.top();
            stk.pop();
        }

        reverse(newS.begin(), newS.end());
        stk = stack<char>();
        s = newS;
        len = s.length();
        
        for (int i = 0; i < len; i++) {
            if (stk.empty()) {
                stk.push(s[i]);
                continue;
            }

            if (stk.top() == sChar && s[i] == fChar) {
                ans += sNum;
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }
        return ans;
    }
};
