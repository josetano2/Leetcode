function triangularSum(nums: number[]): number {
    let n = nums.length - 1;
    if(n == 0) return nums[0];
    while(n--) {
        let curr: number[] = [];
        for(let i = 0; i <= n; i++) {
            curr.push((nums[i] + nums[i + 1]) % 10);
        }
        nums = curr;
    }
    return nums[0];
};