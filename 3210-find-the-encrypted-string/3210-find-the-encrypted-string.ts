function getEncryptedString(s: string, k: number): string {
    var ss = s + s, ans = "", n = s.length;
    k %= n;
    [...s].forEach((c: string, i: number) => {
        ans += ss[i + k];
    })
    return ans;
};