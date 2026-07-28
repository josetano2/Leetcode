function smallestPalindrome(s: string): string {
    let n = s.length, sb = s.substring(0, Math.floor(n / 2));

    let f = sb.split('').sort().join(''), b = f.split('').reverse().join('');
    if(n % 2 != 0) f += s[Math.floor(n / 2)];

    return f + b;
};