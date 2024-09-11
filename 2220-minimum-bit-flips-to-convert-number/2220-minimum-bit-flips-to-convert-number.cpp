class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorVal = start ^ goal, counter = 0;
        while(xorVal > 0){
            if(xorVal & 1) counter++;
            xorVal = xorVal >> 1;
        }
        return counter;
    }
};