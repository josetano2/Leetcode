function maxNumberOfBalloons(text: string): number {
    let balloon: string[] = ['b', 'a', 'l', 'o', 'n'], freq = _.countBy(text), ans = Infinity;
    for(const b of balloon) {
        if(!freq[b] || (freq[b] && (b == 'l' || b == 'o') && freq[b] <= 1)) return 0;
    }
    
    freq['l'] = Math.floor(freq['l'] / 2);
    freq['o'] = Math.floor(freq['o'] / 2);
    for(const b of balloon) {
        console.log(freq[b])
        ans = Math.min(ans, freq[b]);
    }

    return ans;
};