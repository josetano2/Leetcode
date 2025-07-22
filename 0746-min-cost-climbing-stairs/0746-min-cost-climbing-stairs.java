class Solution {

    int[] cache;
    int len;

    public int dp(int[] cost, int idx) {
        if (idx >= len)
            return 0;
        if (cache[idx] != -1)
            return cache[idx];

        cache[idx] = cost[idx] + Math.min(dp(cost, idx + 1), dp(cost, idx + 2));
        return cache[idx];
    }

    public int minCostClimbingStairs(int[] cost) {
        len = cost.length;
        cache = new int[len];
        Arrays.fill(cache, -1);
        return Math.min(dp(cost, 0), dp(cost, 1));
    }
}