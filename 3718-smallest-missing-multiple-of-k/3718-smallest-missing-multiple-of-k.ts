function missingMultiple(nums: number[], k: number): number {
    const arr: boolean[] = new Array(101).fill(false);
    nums.forEach(n => {
        if(n % k == 0) arr[n] = true;
    })

    for(let i = k; i <= 100; i += k) if(!arr[i]) return i;

    let x: number = 0;
    while(x <= 100) x += k;
    return x;
};