class Solution {
    public boolean checkInclusion(String s1, String s2) {

        HashMap<Character, Integer> freq = new HashMap<>();
        int len1 = s1.length(), len2 = s2.length();

        for (int i = 0; i < len1; i++) {
            freq.put(s1.charAt(i), freq.getOrDefault(s1.charAt(i), 0) + 1);
        }

        int l = 0, r = 0;

        HashMap<Character, Integer> buffer = new HashMap<>();

        // dcda
        // l = 0, r = 1
        // buffer
        // d = 1
        while (r < len2) {
            if (freq.get(s2.charAt(r)) == null) {
                l++;
                r = l;
                buffer.clear();
            } else {
                buffer.put(s2.charAt(r), buffer.getOrDefault(s2.charAt(r), 0) + 1);
                r++;
            }

            if (freq.equals(buffer)) {
                return true;
            }

            System.out.println(buffer);
            System.out.println(l);
            System.out.println(r);
            System.out.println();

            if (r - l >= len1) {
                buffer.put(s2.charAt(l), buffer.getOrDefault(s2.charAt(l), 0) - 1);
                l++;
            }
        }

        return freq.equals(buffer);

    }
}