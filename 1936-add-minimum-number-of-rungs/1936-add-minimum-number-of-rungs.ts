function addRungs(rungs: number[], dist: number): number {
    let ans: number = 0;
    if(rungs[0] > dist) ans += Math.floor((rungs[0] - 1) / dist);

    for(let i = 0; i < rungs.length - 1; i++) {
        if(rungs[i + 1] - rungs[i] > dist) ans += Math.floor(((rungs[i + 1] - rungs[i]) - 1) / dist); 
    }

    return ans;
};