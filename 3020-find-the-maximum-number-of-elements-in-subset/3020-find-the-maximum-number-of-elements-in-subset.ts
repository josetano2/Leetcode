function maximumLength(nums: number[]): number {
    const freq = new Map<number, number>();

    for (const n of nums) {
        freq.set(n, (freq.get(n) ?? 0) + 1);
    }

    console.log(freq);

    let ans = 1;
    for (const i of freq.keys()) {
        if(i === 1) {
            let o = freq.get(i);
            if(o > 1) {
                if(o % 2 === 0) o--;
                ans = Math.max(ans, o);
            }
            continue;
        }

        if (freq.get(i)! >= 2) {
            let curr = i, len = 2;
            while ((freq.get(curr ** 2) ?? 0) >= 2) {
                curr = curr ** 2;

                if (!freq.get(curr ** 2)) len++;
                else len += 2;
            }

            if (freq.get(curr ** 2)) len++;

            if (len != 2) ans = Math.max(ans, len);
        }
    }
    
    
    return ans;
};