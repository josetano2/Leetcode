function eventualSafeNodes(graph: number[][]): number[] {
    let n = graph.length;
    const state: number[] = new Array(n).fill(0);

    // 0 -> unvisited
    // 1 -> visiting (not finished)
    // 2 -> finished
    function dfs(node: number) {
        if (state[node] === 1) return false;
        if (state[node] === 2) return true;

        state[node] = 1;
        for (const neighbor of graph[node]) {
            if (!dfs(neighbor)) return false;
        }
        state[node] = 2;
        return true;
    }

    const ans: number[] = [];
    for (let i = 0; i < n; i++) {
        if (dfs(i)) ans.push(i);
    }

    return ans;
};