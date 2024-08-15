
class Solution {
public:
    bool isPalindrome(string s) {
        
        int len = s.length();
        string fin = "";

        for(int i = 0; i < len; i++){
            if(isalnum(s[i])){
                if(isupper(s[i])){
                    s[i] += 32;
                }
            fin.push_back(s[i]);
            }
        }

        int lenFin = fin.length();
        for(int i = 0; i < lenFin / 2; i++){
            cout << fin[i] << " " << fin[lenFin - i - 1] << endl;
            if(fin[i] != fin[lenFin - i - 1]){
                return false;
            }
        }

        return true;

    }
};