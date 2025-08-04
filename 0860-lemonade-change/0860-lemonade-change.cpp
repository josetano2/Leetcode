class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int fiveD = 0, tenD = 0;

        for (auto x : bills) {
            int change = x - 5;
            if (change != 0) {
                // Count each of the available bill
                int temp = change;
                while(temp > 0) {
                    if(temp >= 10 && tenD > 0) {
                        tenD--;
                        temp -= 10;
                    }
                    else if(fiveD > 0) {
                        fiveD--;
                        temp -= 5;
                    }
                    else {
                        return false;
                    }
                }
            }
            if(x == 5) fiveD++;
            if(x == 10) tenD++;
        }

        return true;
    }
};