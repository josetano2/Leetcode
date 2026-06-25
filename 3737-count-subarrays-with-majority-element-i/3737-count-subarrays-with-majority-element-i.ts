function countMajoritySubarrays(nums: number[], target: number): number {
    let ans: number = 0, ct: number = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === target) {
            ct++; ans++;
        }
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[j] === target) ct++;

            if (ct > Math.floor(j - i + 1) / 2) ans++;
        }
        ct = 0;
    }

    return ans;
};