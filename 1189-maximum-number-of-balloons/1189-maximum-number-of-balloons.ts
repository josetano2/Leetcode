function maxNumberOfBalloons(text: string): number {
    let freq = _.countBy(text);
    return Math.min(
        freq['b'] ?? 0, 
        freq['a'] ?? 0, 
        Math.floor((freq['l'] ?? 0) / 2), 
        Math.floor((freq['o'] ?? 0) / 2) ?? 0, 
        freq['n'] ?? 0
    );
};