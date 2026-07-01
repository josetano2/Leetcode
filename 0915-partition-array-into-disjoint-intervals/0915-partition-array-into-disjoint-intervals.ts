function partitionDisjoint(nums: number[]): number {
    let n: number = nums.length, pfix: number[] = new Array(n).fill(0), sfix: number[] = new Array(n).fill(0);

    pfix[0] = nums[0];
    for(let i = 1; i < n; i++) pfix[i] = Math.max(nums[i], pfix[i - 1]);

    sfix[n - 1] = nums[n - 1];
    for(let i = n - 2; i >= 0; i--) sfix[i] = Math.min(nums[i], sfix[i + 1]);
    

    for(let i = 1; i < n; i++) if(pfix[i - 1] <= sfix[i]) return i;
    return n;
};