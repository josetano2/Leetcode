function distanceTraveled(mainTank: number, additionalTank: number): number {
    let ans: number = 0, c: number = 0;
    while(mainTank > 0) {
        mainTank--;
        ans += 10;
        c++;

        if(c === 5) {
            c = 0;
            if(additionalTank > 0) {
                mainTank++;
                additionalTank--;
            }
        }
    }

    return ans;
};