class Solution {
public:
    string processStr(string s) {
        string res = "";

        for(auto &c : s) {
            if(c >= 'a' && c <= 'z') res += c;
            else if(c == '#') res += res;
            else if(c == '%') reverse(res.begin(), res.end());
            else if(c == '*' && res.size() > 0) res.pop_back();
        }
        return res;
    }
};