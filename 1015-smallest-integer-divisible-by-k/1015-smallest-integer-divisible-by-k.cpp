class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0) return -1;
        if(k == 1) return 1;

        long long int curr = 1;
        int i = 1;
        while(true) {
            if(curr % k == 0) return i;
            curr = (curr * 10 + 1) % k;
            i++;
        }

        return -1;
    }
};