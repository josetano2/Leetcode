function majorityElement(nums: number[]): number[] {
    const freq = new Map<number, number>(), nn: number = Math.floor(nums.length / 3);
    for(const n of nums) {
        freq.set(n, (freq.get(n) ?? 0) + 1);
    }

    let ans: number[] = [];
    for(const [k, v] of freq) {
        if(v > nn) {
            ans.push(k);
        }
    }

    return ans;
};