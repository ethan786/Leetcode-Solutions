class MinStack {
public:
        stack<int> temp;
        stack<int> s;
    MinStack() {
    }
    
    void push(int val) {
        if(temp.empty() || val <= temp.top()) {
            temp.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(!temp.empty() and s.top() == temp.top()) {
            temp.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return temp.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */