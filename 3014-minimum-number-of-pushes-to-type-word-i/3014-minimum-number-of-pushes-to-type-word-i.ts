function minimumPushes(word: string): number {
    let n = word.length, cost = 0, mul = 1;

    while(n > 0) {
        let curr = n >= 8 ? 8 : n;
        cost += curr * mul;
        n -= 8;
        mul++;

    }

    return cost;
};