class MinStack {
public:

    stack<int> stk;
    int min;

    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        stk.push(val);
        if(val < min){
            min = val;
        }
    }
    
    void pop() {
        int temp = top();
        stk.pop();

        if(temp == min){
            stack<int> temp = stk;
            int len = temp.size();
            min = INT_MAX;

            while(!temp.empty()){
                if(temp.top() < min){
                    min = temp.top();
                }
                temp.pop();
            }
        }
        
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min;
    }
};