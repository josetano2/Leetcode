

function longestBeautifulSubstring(word: string): number {
    const vowels = ['a', 'e', 'i', 'o', 'u'];
    let n: number = word.length, curr: number = 0, start = -1, ans = -Infinity;

    for (let i = 0; i < n; i++) {
        if(curr === 0) {
            if(word[i] === 'a') {
                start = i;
                curr = 1;
            }
            continue;
        }

        const expected = vowels[curr - 1], next = vowels[curr];

        if(word[i] === expected) {
            continue;
        }
        else if(curr < 5 && word[i] === next) {
            curr++;
        }
        else {
            if(curr === 5) ans = Math.max(ans, i - start);
            if(word[i] === 'a') {
                start = i;
                curr = 1;
            }
            else {
                start = -1;
                curr = 0;
            }
        }
    }
    
    if(curr === 5) ans = Math.max(ans, n - start);
    return ans === -Infinity ? 0 : ans;
};