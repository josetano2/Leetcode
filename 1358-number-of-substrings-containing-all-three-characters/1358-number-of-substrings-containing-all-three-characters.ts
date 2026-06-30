function numberOfSubstrings(s: string): number {
    let l = 0, freq = new Map<string, number>, ans = 0;
    for(let i = 0; i < s.length; i++) {
        freq.set(s[i], (freq.get(s[i]) ?? 0) + 1);

        while((freq.get('a') ?? 0) > 0 && (freq.get('b') ?? 0) > 0 && (freq.get('c') ?? 0) > 0) {
            ans += s.length - i;
            freq.set(s[l], freq.get(s[l]) - 1);
            l++;
        }
    }

    return ans;
};