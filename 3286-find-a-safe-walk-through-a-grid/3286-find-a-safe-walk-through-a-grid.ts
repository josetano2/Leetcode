function findSafeWalk(grid: number[][], health: number): boolean {
    let m = grid.length, n = grid[0].length;
    const xArr: number[] = [-1, 1, 0, 0], yArr: number[] = [0, 0, -1, 1];

    function checker(x: number, y: number): boolean {
        if (x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    const dist: number[][] = Array.from({ length: m }, () => Array(n).fill(Infinity));
    dist[0][0] = grid[0][0];

    const d: [number, number][] = [];
    d.unshift([0, 0]);

    while (d.length > 0) {
        const [x, y] = d[0];
        d.shift();

        for (let i = 0; i < 4; i++) {
            let newX: number = x + xArr[i], newY: number = y + yArr[i];
            if (checker(newX, newY)) {
                if(dist[x][y] + grid[newX][newY] < dist[newX][newY]) {
                    dist[newX][newY] = dist[x][y] + grid[newX][newY];
                    if(dist[newX][newY] == 0) d.unshift([newX, newY]);
                    else d.push([newX, newY]);
                }
            }
        }
    }

    return dist[m - 1][n - 1] < health ? true : false;
};