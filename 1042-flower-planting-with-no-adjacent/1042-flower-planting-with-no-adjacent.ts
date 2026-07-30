function gardenNoAdj(n: number, paths: number[][]): number[] {
    const graph: number[][] = Array.from({ length: n + 1 }, () => []);
    const ans: number[] = new Array(n).fill(0);
    for(const [a, b] of paths) {
        graph[a].push(b);
        graph[b].push(a);
    }

    for(let i = 1; i <= n; i++) {
        const colors = new Array(5).fill(0);

        for(const neighbor of graph[i]) {
            colors[ans[neighbor - 1]] = 1;
        }

        for(let j = 1; j <= 4; j++) {
            if(colors[j] === 0) {
                ans[i - 1] = j;
                break;
            }
        }
    }

    return ans;
};