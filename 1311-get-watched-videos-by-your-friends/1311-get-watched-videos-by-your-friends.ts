function watchedVideosByFriends(watchedVideos: string[][], friends: number[][], id: number, level: number): string[] {
    const queue: number[] = friends[id];
    const visited = new Set<number>(friends[id]);
    visited.add(id);
    let l = 1;

    while(l < level) {
        const nextQueue: number[] = [];
        let n = queue.length;

        for(let i = 0; i < n; i++) {
            const node = queue[i];

            for(const f of friends[node]) {
                if(!visited.has(f)) {
                    visited.add(f);
                    nextQueue.push(f);
                }
            }
        }
        queue.length = 0;
        queue.push(...nextQueue);
        l++;
    }

    const freq = new Map<string, number>();
    for(let i = 0; i < queue.length; i++) {
        let wv: string[] = watchedVideos[queue[i]];

        for(const w of wv) {
            freq.set(w, (freq.get(w) ?? 0) + 1)
        }
    }
    const sorted = [...freq.entries()].sort((a, b) => 
        a[1] !== b[1] ? a[1] - b[1] : a[0].localeCompare(b[0])
    );

    return sorted.map(([v]) => v);
};