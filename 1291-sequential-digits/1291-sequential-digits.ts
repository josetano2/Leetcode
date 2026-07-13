function sequentialDigits(low: number, high: number): number[] {
    const template = '123456789', ans: number[] = [];

    let sz = low.toString().length, l = 0, r = sz, curr = 0;

    while (curr <= high && sz <= 9) {
        curr = Number(template.substring(l, r));
        if (curr >= low && curr <= high) ans.push(curr);
        l++; r++;
        if (r > 9) {
            sz++;
            l = 0; r = sz;
        }
    }

    return ans;
};