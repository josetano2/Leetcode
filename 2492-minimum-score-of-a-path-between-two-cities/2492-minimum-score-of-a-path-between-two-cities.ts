function minScore(n: number, roads: number[][]): number {
    const graph: [number, number][][] = Array.from({ length: n + 1 }, () => []);

    for(const [a, b, w] of roads) {
        graph[a].push([b, w]);
        graph[b].push([a, w]);
    }

    const visited = new Set<number>([1]);
    const queue = [1];

    while(queue.length) {
        const node = queue.pop();

        for(const [next] of graph[node]) {
            if(!visited.has(next)) {
                visited.add(next);
                queue.push(next);
            }
        }   
    }

    let ans = Infinity;
    for(const [a, _, w] of roads) {
        if(visited.has(a)) ans = Math.min(ans, w);
    }

    return ans;
};