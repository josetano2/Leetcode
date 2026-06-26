function minCuttingCost(n: number, m: number, k: number): number {
    let ans: number = 0;
    if(n > k) ans += (n - k) * k
    if(m > k) ans += (m - k) * k
    return ans;
};