function numOfStrings(patterns: string[], word: string): number {
    
    let len: number = word.length, freq = new Set<string>(), ans: number = 0;
    for(let i = 0; i < len; i++) {
        let curr: string = "";

        for(let j = i; j < len; j++) {
            curr += word[j];
            freq.add(curr);
        }
    }

    for(const p of patterns) {
        if(freq.has(p)) ans++;
    }

    return ans;
};