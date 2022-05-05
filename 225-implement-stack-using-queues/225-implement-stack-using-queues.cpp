class MyStack {
public:
    vector<int> a;
    int ni,tp,cap;
    MyStack() {
        for(int i=0;i<300;i++){
            a.push_back(0);
        }
        ni = 0;
        tp = 0;
        cap = 0;
    }
    
    void push(int x) {
        a[ni] = x;
        ni++;
        cap++;
    }
    
    int pop() {
        if(cap != 0){
            cap--;
            ni--;
            return a[ni];
        }
        return -1;
    }
    
    int top() {
        if(cap != 0){
            return a[ni-1];
        }
        return -1;
    }
    
    bool empty() {
        return cap == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */