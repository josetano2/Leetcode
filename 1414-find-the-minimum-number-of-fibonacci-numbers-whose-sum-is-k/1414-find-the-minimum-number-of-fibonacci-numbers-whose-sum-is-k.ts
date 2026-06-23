function findMinFibonacciNumbers(k: number): number {
    const fib = new Array(100).fill(0);
    fib[0] = 1;
    fib[1] = 1;

    for(let i = 2; i < 100; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    let ans = 0;
    for(let i = 99; i >= 0 && k > 0; i--) {
        if(k >= fib[i]) {
            k -= fib[i];
            ans++;
        }
    }

    return ans;
};