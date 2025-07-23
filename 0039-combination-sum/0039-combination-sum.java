class Solution {

    List<List<Integer>> ans;

    public void backtrack(List<Integer> curr, int currSum, int[] candidates, int target) {
        if (currSum == target) {
            ans.add(new ArrayList<>(curr));
            return;
        }

        for (int i = 0; i < candidates.length; i++) {
            if (currSum + candidates[i] > target || (!curr.isEmpty() && candidates[i] > curr.get(curr.size() - 1)))
                continue;
            curr.add(candidates[i]);
            currSum += candidates[i];

            System.out.println("Before: " + curr + " " + currSum);

            backtrack(curr, currSum, candidates, target);
            currSum -= curr.get(curr.size() - 1);
            curr.remove(curr.size() - 1);

            System.out.println("After: " + curr + " " + currSum);
            System.out.println();
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        ans = new ArrayList<>();
        backtrack(new ArrayList<>(), 0, candidates, target);
        return ans;
    }
}