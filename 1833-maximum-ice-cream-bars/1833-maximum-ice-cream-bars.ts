function maxIceCream(costs: number[], coins: number): number {
    const freq = _.countBy(costs), mx = _.max(costs);
    let i = 0, ans = 0;
    for(i < _.min(costs); i <= mx && coins >= i;) {
        if(freq[i] ?? 0 > 0) {
            coins -= i;
            freq[i]--;
            ans++;
        }
        else i++;
    }
    return ans;
};