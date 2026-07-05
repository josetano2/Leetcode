function maxDigitRange(nums: number[]): number {

    function findMinMax(n: number): number {
        let min: number = Infinity, max: number = -Infinity, nstr: string = n.toString();
        for (const c of nstr) {
            let curr: number = Number(c);
            min = Math.min(min, curr);
            max = Math.max(max, curr);
        }

        return max - min;
    }

    const range = new Map<number, number[]>();
    let maxRange: number = -Infinity, ans = 0;

    for (const n of nums) {
        const res: number = findMinMax(n);
        if (!range.has(res)) {
            range.set(res, []);
        }

        range.get(res)!.push(n); 
        maxRange = Math.max(res, maxRange);
    }
    
    
    for(let i = 9; i >= 0; i--) {
        if(range.get(i)) {
            let arr: number[] = range.get(i);

            for(const a of arr) ans += a;
            return ans;
        }
    }

    return ans;
};