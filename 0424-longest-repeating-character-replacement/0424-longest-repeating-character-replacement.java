class Solution {
    public int characterReplacement(String s, int k) {

        int len = s.length();

        int l = 0, r = 0, ans = -1;
        HashMap<Character, Integer> freq = new HashMap<>();
        int windowSize, diff, maxFreq = 0;

        while (r < len) {
            freq.put(s.charAt(r), freq.getOrDefault(s.charAt(r), 0) + 1);
            maxFreq = Math.max(maxFreq, freq.get(s.charAt(r)));

            windowSize = r - l + 1;
            // diff = windowSize - maxFreq;
            // if (diff <= k) {
            //     ans = Math.max(ans, r - l + 1);
            // }

            if(windowSize - maxFreq > k) {
                freq.put(s.charAt(l), freq.get(s.charAt(l)) - 1);
                l++;
            }
            ans = Math.max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
}

// ABAB