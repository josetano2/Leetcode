function removeCoveredIntervals(intervals: number[][]): number {
    intervals.sort((a, b) => a[0] - b[0] || b[1] - a[1]);

    let ans = 0, mx = -Infinity;
    
    for(const [start, end] of intervals) {
        if(end > mx) {
            ans++;
            mx = end;
        }
    }
    return ans;
};