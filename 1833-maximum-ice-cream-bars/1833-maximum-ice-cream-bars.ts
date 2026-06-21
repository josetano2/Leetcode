function maxIceCream(costs: number[], coins: number): number {
    costs.sort((a, b) => a - b);
    let i = 0;
    for (i = 0; i < costs.length; i++) {
        if (coins - costs[i] < 0) break;
        coins -= costs[i];
    }
    return i;
};