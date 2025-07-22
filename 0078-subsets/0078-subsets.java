class Solution {

    List<List<Integer>> ans;
    List<Integer> subsets;
    int[] numbers;

    public void generateSubsets(int idx, int len) {
        if (idx >= len) {
            ans.add(new ArrayList<>(subsets));
            return;
        }

        subsets.add(numbers[idx]);
        generateSubsets(idx + 1, len);

        subsets.remove(subsets.size() - 1);
        generateSubsets(idx + 1, len);
    }

    public List<List<Integer>> subsets(int[] nums) {
        ans = new ArrayList<>();
        subsets = new ArrayList<>();
        numbers = nums;
        generateSubsets(0, nums.length);

        return ans;
    }
}