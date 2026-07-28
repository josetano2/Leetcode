function findLongestWord(s: string, dictionary: string[]): string {
    function isDoable(a: string): boolean  {
        let j = 0;
        for(let i = 0; i < s.length; i++) {
            if(s[i] === a[j]) j++;
            if(j === a.length) return true;
        }
        return false;
    }

    let ans = "";
    for(const d of dictionary) {
        if(isDoable(d)) {
            if((d.length > ans.length) || (d.length === ans.length && d < ans)) {
                ans = d;
            }
        }
    }

    return ans;
};