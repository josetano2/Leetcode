function camelMatch(queries: string[], pattern: string): boolean[] {
    
    let ans: boolean[] = [], target = pattern.length;
    for(const q of queries) {
        let j = 0;
        for(let i = 0; i < q.length; i++) {
            if(q[i] === pattern[j] && j < target) {
                j++;
            }
            else if(/[A-Z]/.test(q[i])) {
                j = -1;
                break;
            }
        }

        if(j === target) ans.push(true);
        else ans.push(false);
    }

    return ans;
};