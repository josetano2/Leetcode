function maximumElementAfterDecrementingAndRearranging(arr: number[]): number {
    arr.sort((a, b) => a - b);

    arr[0] = 1;
    for(let i = 1; i < arr.length; i++) {
        if(Math.abs(arr[i] - arr[i - 1]) <= 1) continue;

        if(arr[i] > arr[i - 1]) {
            arr[i] = arr[i - 1] + 1;
        }
    }
    console.log(arr)
    return arr[arr.length - 1];
};