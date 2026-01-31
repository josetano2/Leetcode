class Solution {
public:

    int getGreatestProperDivisor(int n) {
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return n / i;
        }
        return 1;
    }

    int minOperations(vector<int>& nums) {
        int ans = 0
        ;
        for(int i = nums.size() - 1; i > 0; i--) {
            int curr = nums[i], next = nums[i - 1];
            if(next > curr) {
                int gpd = getGreatestProperDivisor(next);
                next = gpd == next ? next : next / gpd;
                cout << gpd << " " << next << " " << curr << endl;
                nums[i - 1] = next;
                if(next > curr) return -1;
                ans++;
            }
        }
        return ans;
    }
};