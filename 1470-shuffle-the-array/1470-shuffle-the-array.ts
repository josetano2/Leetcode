function shuffle(nums: number[], n: number): number[] {
    return Array.from( { length: n }, (_, i) => [nums[i], nums[i + n]]).flat();
};