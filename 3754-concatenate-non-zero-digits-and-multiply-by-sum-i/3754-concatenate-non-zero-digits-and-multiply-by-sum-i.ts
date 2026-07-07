function sumAndMultiply(n: number): number {
    let nstr = n.toString(), s = "", sum = 0;
    for(const c of nstr) {
        if(c !== '0') {
            s += c;
            sum += Number(c);
        }
    }
    return Number(s) * sum;
};