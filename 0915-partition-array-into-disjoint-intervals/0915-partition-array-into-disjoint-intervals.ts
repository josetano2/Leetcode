function partitionDisjoint(nums: number[]): number {
    let lmx = nums[0], cmx = nums[0], partition = 0;
    for(let i = 1; i < nums.length; i++) {
        cmx = Math.max(cmx, nums[i]);

        if(nums[i] < lmx) {
            lmx = cmx;
            partition = i;
        }
    }
    return partition + 1;
};