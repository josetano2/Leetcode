class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0){
            return false;
        }

        // 121
        long long int multiplier = 1, temp = x, len = 0;
        while(temp > 0){
            temp /= 10;
            multiplier *= 10;
            len++;
        }

        long long int res = 1;
        for(int i = 0; i < len / 2; i++){
            multiplier /= 10;
            long long int left = (x / multiplier) % 10, right = (x % (10 * res)) / res;
            cout << left << " " << right << endl;
            res *= 10;

            if(left != right){
                return false;
            }
        }

        cout << len << " " << multiplier << endl;
        return true;
        
        
    }
};