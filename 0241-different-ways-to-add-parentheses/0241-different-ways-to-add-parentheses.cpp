class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {

        vector<int> ans;

        int len = expression.length();
        bool hasOperator = false;

        for(int i = 0; i < len; i++){

            // cek apakah skrg operator or not
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                hasOperator = true;

                // recursion ke kiri
                vector<int> left = diffWaysToCompute(expression.substr(0, i));

                // recursion ke kanan
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, len));

                // merge kiri & kanan, itung operationnya
                for(auto x : left){
                    for(auto y : right){
                        if(expression[i] == '+') ans.push_back(x + y);
                        if(expression[i] == '-') ans.push_back(x - y);
                        if(expression[i] == '*') ans.push_back(x * y);
                    }
                }
            }
        }

        // kalo ampe ujung recursion ada 1 nomor doang, push ke ans
        if(!hasOperator) ans.push_back(stoi(expression));

        return ans;
        
    }
};
