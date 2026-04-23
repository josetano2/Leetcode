class Solution {
public:
    int reachNumber(int target) {
        long long curr = 1;
        target = abs(target);
        while(true) {
            long long tot = curr * (curr + 1) / 2;

            if(tot >= target && (target - tot) % 2 == 0) return curr;
            curr++;
        }
        return -1;
    }
};