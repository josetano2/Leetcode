class Solution {
    public int maximumLength(int[] nums, int k) {
        HashMap<Integer, Integer> tracker = new HashMap<>();

        int len = nums.length;
        int[][] dp = new int[k][k];
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                dp[i][j] = 0;
            }
        }

        int ans = 0;
        for(int i = 0; i < len; i++){
            int curr = nums[i] % k;
            
            for(int j = 0; j < k; j++) {
                dp[j][curr] = dp[curr][j] + 1;
                ans = Math.max(ans, dp[j][curr]);
            }
        }
        return ans;
    }
}

// 1 + 2 = 3 % 2 = 1
// 2 + 3 = 5 % 2 = 1
// 3 + 4 = 7 % 2 = 1
// 4 + 5 = 9 % 2 = 1


// 1 + 4 = 5 % 3 = 2