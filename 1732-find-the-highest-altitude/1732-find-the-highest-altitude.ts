function largestAltitude(gain: number[]): number {
    var ans = 0, curr = 0;
    for(var x of gain) {
        curr += x;
        if(curr > ans) {
            ans = curr;
        }
    }
    return ans;
};