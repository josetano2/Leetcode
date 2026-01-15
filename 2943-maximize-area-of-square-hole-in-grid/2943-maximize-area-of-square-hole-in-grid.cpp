class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // n -> x, m -> y
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int areaF = 1, i = 0;
        while(i < vBars.size() && i < hBars.size() && hBars[i] == vBars[i]) {
            areaF++; i++;
        }   

        int tempH = 1, tempV = 1, h = 1, v = 1;
        // 2 3 4 5
        // 6 33 34 36 41
        for(int i = 0; i < hBars.size() - 1; i++) {
            if(hBars[i] + 1 == hBars[i + 1]) {
                tempH++;
            }
            else {
                h = max(tempH, h);
                tempH = 1;
            }
        }
        for(int i = 0; i < vBars.size() - 1; i++) {
            if(vBars[i] + 1 == vBars[i + 1]) {
                tempV++;
            }
            else {
                v = max(tempV, v);
                tempV = 1;
            }
        }
        h = max(tempH, h);
        v = max(tempV, v);

        int areaL = min(h, v) + 1;
        return max(pow(areaF, 2), pow(areaL, 2));
    }
};