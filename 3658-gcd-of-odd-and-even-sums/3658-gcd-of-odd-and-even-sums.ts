function gcdOfOddEvenSums(n: number): number {
    let os = n * n, es = n * (n + 1);

    while (es != 0) {
        let temp = es;
        es = os % es;
        os = temp;
    }
    return os;
};