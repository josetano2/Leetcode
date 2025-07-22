class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();

        int l = 0, r = 0, len = nums.length, ans = 0, temp = 0;

        while (r < len) {

            if(map.get(nums[r]) == null) {
                map.put(nums[r], r);
                temp += nums[r];
                r++;
            }
            else{
                ans = Math.max(ans, temp);
                
                int lastIdx = map.get(nums[r]);
                while(l <= lastIdx) {
                    temp -= nums[l];
                    l++;
                }
                map.remove(nums[r]);
            }

            // if (!set.contains(nums[r])) {
            //     set.add(nums[r]);
            //     temp += nums[r];
            //     r++;
            // } else {
            //     ans = Math.max(ans, temp);
            //     set.clear();
            //     l = r - 1;
            //     temp = nums[l];

            // }
        }
        return Math.max(ans, temp);
    }
}