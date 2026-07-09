function strongPasswordCheckerII(password: string): boolean {
    const a = {
        lc: false,
        uc: false,
        dg: false,
        sy: false,
    };

    for (let i = 0; i < password.length; i++) {
        if (/[A-Z]/.test(password[i])) a.uc = true;
        if (/[a-z]/.test(password[i])) a.lc = true;
        if (/[0-9]/.test(password[i])) a.dg = true;
        if (/[^A-Za-z0-9\s]/.test(password[i])) a.sy = true;

        if(i != password.length - 1) {
            if(password[i] === password[i + 1]) return false;
        }
    }

    return a.lc && a.uc && a.dg && a.sy && password.length >= 8;
};