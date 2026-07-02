function findReplaceString(s: string, indices: number[], sources: string[], targets: string[]): string {
    let n: number = indices.length;
    const valid = new Map<number, number>();

    for(let i = 0; i < n; i++) {
        let start = indices[i], end = start + sources[i].length, cut = s.substring(start, end);
        // console.log(cut, " ", sources[i]);
        // console.log(cut.includes(sources[i]));

        if(cut === sources[i]) {
            valid.set(start, i);
        }
    }
    
    let result: string = "", curr: number = 0;
    while(curr < s.length) {
        if(valid.has(curr)) {
            result += targets[valid.get(curr)];
            curr += sources[valid.get(curr)].length;
        }
        else {
            result += s[curr];
            curr++;
        }
    }

    return result;
};