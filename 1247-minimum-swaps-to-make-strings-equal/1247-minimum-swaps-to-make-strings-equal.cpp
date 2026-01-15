class Solution {
public:
    int minimumSwap(string s1, string s2) {

        int xy = 0, yx = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == 'x' && s2[i] == 'y') xy++;
            if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }

        if((xy + yx) % 2 != 0) return -1;

        int swaps = 0;
        swaps += xy / 2;
        swaps += yx / 2;
        if(xy % 2 == 1 && yx % 2 == 1) swaps += 2;
        return swaps;
    }
};