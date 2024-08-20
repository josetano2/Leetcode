class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> uMap;

        uMap['I'] = 1;
        uMap['V'] = 5;
        uMap['X'] = 10;
        uMap['L'] = 50;
        uMap['C'] = 100;
        uMap['D'] = 500;
        uMap['M'] = 1000;

        int len = s.size(), tot = 0;


        for(int i = 0; i < len; i++){
            int temp = 0;
            if(i != len - 1){
                if(s[i] == 'I'){
                    if(s[i+1] == 'V'){
                        temp = 4;
                    }
                    else if(s[i+1] == 'x'){
                        temp = 9;
                    }
                }
                else if(s[i] == 'X'){
                    if(s[i+1] == 'L'){
                        temp = 40;
                    }
                    else if(s[i+1] == 'C'){
                        temp = 90;
                    }
                }
                else if(s[i] == 'C'){
                    if(s[i+1] == 'D'){
                        temp = 400;
                    }
                    else if(s[i+1] == 'M'){
                        temp = 900;
                    }
                }
                else{
                    temp = uMap[s[i]];
                }
            }
            else{
                temp = uMap[s[i]];
            }
            tot += temp;
        }

        return tot;

    }
};