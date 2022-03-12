class StockSpanner {
    stack<pair<int,int>> st;
    int i;
public:
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price)
            st.pop();
        i++;
        int k = st.empty() ? i : (i - st.top().second);
        st.push({price,i});
        return k;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */