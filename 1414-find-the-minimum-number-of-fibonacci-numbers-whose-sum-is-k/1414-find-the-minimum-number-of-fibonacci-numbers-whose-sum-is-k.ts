function findMinFibonacciNumbers(k: number): number {
    const fib = [1, 1]

    for(let i = 2; fib[i - 1] < k; i++) {
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