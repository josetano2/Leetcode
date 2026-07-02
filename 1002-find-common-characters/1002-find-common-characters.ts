function commonChars(words: string[]): string[] {
    const wordFreq = (w: string): Map<string, number> => {
        const freq = new Map<string, number>();
        for (const c of w) freq.set(c, (freq.get(c) ?? 0) + 1);
        return freq;
    };

    let minFreq = wordFreq(words[0]);
    for(let i = 1; i < words.length; i++) {
        const curr = wordFreq(words[i]);
        for(const [k, v] of minFreq) {
            minFreq.set(k, Math.min(v, curr.get(k) ?? 0));
        }
    }

    const ans: string[] = [];
    for(const [k, v] of minFreq) {
        for(let i = 0; i < v; i++) ans.push(k);
    }

    return ans;
};