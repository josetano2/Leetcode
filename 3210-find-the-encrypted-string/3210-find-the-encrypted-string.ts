function getEncryptedString(s: string, k: number): string {
    var ss = s + s, ans = "", n = s.length;
    k %= n;
    for(let i = 0; i < n; i++) ans += ss[i + k];
    return ans;
};