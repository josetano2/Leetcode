function numIslands(grid: string[][]): number {
    let m = grid.length, n = grid[0].length;

    const visited: boolean[][] = Array.from({ length: m }, () => new Array(n).fill(false));

    const xArr = [1, 0, -1, 0];
    const yArr = [0, 1, 0, -1];

    function bfs(x, y) {
        const q: [number, number][] = [[x, y]];
        visited[x][y] = true;

        while (q.length > 0) {
            const [row, col] = q.shift();

            for (let i = 0; i < 4; i++) {
                const newX = row + xArr[i], newY = col + yArr[i];

                if (isValid(newX, newY)) {
                    visited[newX][newY] = true;
                    q.push([newX, newY]);
                }
            }
        }
    }

    function isValid(newX: number, newY: number): boolean {
        if (newX < 0 || newX >= m || newY < 0 || newY >= n || visited[newX][newY] || grid[newX][newY] === "0") return false;
        return true;
    }

    let ans = 0;
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            if(grid[i][j] === "1" && !visited[i][j]) {
                bfs(i, j);
                ans++;
            }
        }
    }

    return ans;
};