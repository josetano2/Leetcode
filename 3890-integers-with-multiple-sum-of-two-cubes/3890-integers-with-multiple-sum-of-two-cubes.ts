function findGoodIntegers(n: number): number[] {
    const cubes = new Set<number>();
    let curr: number = 1;
    while(curr ** 3 <= n) {
        cubes.add(curr ** 3);
        curr++; 
    }
    const sums = new Map<number, number>();

    const arr = [...cubes];
    for (let i = 0; i < arr.length; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            const sum = arr[i] + arr[j];
            if (sum <= n) {
                sums.set(sum, (sums.get(sum) ?? 0) + 1);
            }
        }
    }
    return [...sums.keys()].filter(k => sums.get(k) >= 2).sort((a, b) => a - b);
};