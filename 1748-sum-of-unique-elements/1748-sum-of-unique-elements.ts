function sumOfUnique(nums: number[]): number {
    let freq: Map<number, number> = new Map(), ans: number = 0;
    nums.forEach(x => {
        freq.set(x, (freq.get(x) ?? 0) + 1);
    })
    
    freq.forEach((v, k) => v === 1 && (ans += k));
    return ans;
};