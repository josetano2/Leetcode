class Solution {

public:
    bool isValid(string s) {
        stack<char> stk;

        if(s.size() % 2 != 0){
            return false;
        }

        for(auto x : s){
            if(x == '(' || x == '{' || x == '['){
                stk.push(x);
                continue;
            }

            else if(!stk.empty()){
                if(x == ')' && stk.top() == '(' || x == ']' && stk.top() == '[' || x == '}' && stk.top() == '{'){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        

        return stk.empty();

    }
};