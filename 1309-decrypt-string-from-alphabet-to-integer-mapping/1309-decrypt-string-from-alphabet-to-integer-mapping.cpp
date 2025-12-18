class Solution {
public:
    string freqAlphabets(string s) {

        unordered_map<string, char> uMap = {
            {"1", 'a'},   {"2", 'b'},   {"3", 'c'},   {"4", 'd'},
            {"5", 'e'},   {"6", 'f'},   {"7", 'g'},   {"8", 'h'},
            {"9", 'i'},   {"10#", 'j'}, {"11#", 'k'}, {"12#", 'l'},
            {"13#", 'm'}, {"14#", 'n'}, {"15#", 'o'}, {"16#", 'p'},
            {"17#", 'q'}, {"18#", 'r'}, {"19#", 's'}, {"20#", 't'},
            {"21#", 'u'}, {"22#", 'v'}, {"23#", 'w'}, {"24#", 'x'},
            {"25#", 'y'}, {"26#", 'z'}};

        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            string temp = "";
            if (i + 2 < s.size() && s[i + 2] == '#') {
                temp = s.substr(i, 3);
                i += 2;
            } else {
                temp = s[i];
            }
            ans += uMap[temp];
        }

        return ans;
    }
};