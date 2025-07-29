class Solution {
public:
    bool checkValidString(string s) {

        int len = s.length();

        stack<int> open;
        stack<int> star;

        // stack: ()) * count: 1
        // stack: *(

        for (int i = 0; i < len; i++) {
            if(s[i] == '(') {
                open.push(i);
            }
            else if(s[i] == '*') {
                star.push(i);
            }

            else if(s[i] == ')') {
                if(!open.empty()) {
                    open.pop();
                }
                else if(!star.empty()) {
                    star.pop();
                }
                else {
                    return false;
                }
            }
        }

        while(!open.empty() && !star.empty()) {
            if (open.top() > star.top()) {
                return false;
            }
            open.pop();
            star.pop();
        }


        return open.empty();
    }
};