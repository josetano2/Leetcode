function findMissingElements(nums: number[]): number[] {
    let mn = _.min(nums), mx = _.max(nums);

    const freq: number[] = new Array(mx + 1).fill(0);

    for(const n of nums) freq[n] = 1;
    
    const ans: number[] = [];
    for(let i = mn; i <= mx; i++) {
        if(!freq[i]) ans.push(i);
    }
    return ans;
};