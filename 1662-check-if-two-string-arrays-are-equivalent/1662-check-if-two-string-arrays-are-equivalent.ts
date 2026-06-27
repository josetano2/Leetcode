function arrayStringsAreEqual(word1: string[], word2: string[]): boolean {
    let s1 = "", s2 = "";
    for (const c of word1) s1 += c;
    for (const c of word2) s2 += c;
    return s1 === s2;
    
};