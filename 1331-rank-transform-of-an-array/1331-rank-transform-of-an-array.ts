function arrayRankTransform(arr: number[]): number[] {
    const newArr = [...arr];
    newArr.sort((a, b) => a - b);

    let rank = 1, um = new Map<number, number>();
    um.set(newArr[0], rank);

    for(let i = 1; i < arr.length; i++) {
        if(newArr[i] != newArr[i - 1]) rank++;
        if(!um.get(newArr[i])) um.set(newArr[i], rank);
    }

    let ans: number[] = []
    for(let i = 0; i < arr.length; i++) ans.push(um.get(arr[i]));

    return ans;
};