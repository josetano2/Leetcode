class Solution {
private:
    int getVal(){
        int temp = stk.top();
        stk.pop();
        return temp;
    }
public:

    stack<int> stk;

    int evalRPN(vector<string>& tokens) {

        int len = tokens.size();

        int ans = 0;
        for(int i = 0; i < len; i++){
            // masukin operand
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                stk.push(stoi(tokens[i]));
            }
            else{
                int x1 = getVal(), x2 = getVal();
                cout << x1 << " " << x2 << endl;
                if(tokens[i] == "+"){
                    stk.push(x2 + x1);
                }
                else if(tokens[i] == "-"){
                    stk.push(x2 - x1);
                }
                else if(tokens[i] == "*"){
                    stk.push(x2 * x1);
                }
                else if(tokens[i] == "/"){
                    stk.push(x2 / x1);
                }
            }
            
        }

        return stk.top();
    }
};