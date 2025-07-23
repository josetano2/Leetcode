class Solution {

    List<Integer> numbers;
    List<List<Integer>> ans;

    public void permutation(List<Integer> curr, int len, int[] nums) {
        if(curr.size() == len) {
            ans.add(new ArrayList<>(curr));
            return;
        }

        for(int i = 0; i < len; i++) {
            if(curr.contains(nums[i])) continue;
            curr.add(nums[i]);
            permutation(curr, len, nums);
            curr.remove(curr.size() - 1);
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        numbers = new ArrayList<>();
        ans = new ArrayList<>();
        int len = nums.length;
        permutation(new ArrayList<>(), len, nums);
        return ans;
    }
}