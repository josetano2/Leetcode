class Solution {

    int[] cache;

    public int dp(int idx, int[] nums){

        if(idx >= nums.length) {
            return 0;
        }

        if(cache[idx] != -1){
            return cache[idx];
        }

        cache[idx] = Math.max(nums[idx] + dp(idx + 2, nums), dp(idx + 1, nums));

        return cache[idx];
    }

    public int rob(int[] nums) {
        cache = new int[nums.length];
        Arrays.fill(cache, -1);
        return Math.max(dp(0, nums), dp(1, nums));
    }
}