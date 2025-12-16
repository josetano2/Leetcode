class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p] == true) {
                for (int i = p * p; i <= n; i += p) isPrime[i] = false;
            }
        }

        long long sumA = 0, sumB = 0;
        for(int i = 0; i < n; i++) {
            if(isPrime[i]) sumA += nums[i];
            else sumB += nums[i];
        }

        return abs(sumA - sumB);
    }
};