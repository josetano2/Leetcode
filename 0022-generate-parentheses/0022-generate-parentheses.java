class Solution {

    List<String> ans;

    // Condition, max open & close = n
    public void create(String curr, int open, int close, int n) {
        if (open == n && close == n) ans.add(curr);
        if (open < n) create(curr + "(", open + 1, close, n);
        if(close < open) create(curr + ")", open, close + 1, n);
    }

    public List<String> generateParenthesis(int n) {
        ans = new ArrayList<>();
        create("(", 1, 0, n);
        return ans;
    }
}