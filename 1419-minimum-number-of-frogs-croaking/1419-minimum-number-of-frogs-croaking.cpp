class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {

        int c = 0, r = 0, o = 0, a = 0, frogs = 0;
        for(auto& s : croakOfFrogs) {
            if(s == 'c') {
                c++;
            }
            else if(s == 'r') {
                c--; 
                r++;
            }
            else if(s == 'o') {
                r--;
                o++;
            }
            else if(s == 'a') {
                o--;
                a++;
            }
            else {
                a--;
            }
            frogs = max(frogs, c + r + o + a);

            if(c < 0|| r < 0 || o < 0 || a < 0) return -1;
        }

        if(c != 0 || r != 0 || o != 0 || a != 0) return -1;
        return frogs;
    }
};