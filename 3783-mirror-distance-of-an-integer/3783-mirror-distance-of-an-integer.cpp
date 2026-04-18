class Solution {
public:
    int mirrorDistance(int n) {
        int power = log10(n), pos = pow(10, power), temp = n, rev;
        for(int i = 0; i <= power; i++) {
            int end = temp % 10;
            rev += end * pos;
            temp /= 10;
            pos /= 10;
        }

        return abs(rev - n);
    }
};