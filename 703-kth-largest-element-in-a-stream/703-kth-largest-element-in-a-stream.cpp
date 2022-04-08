class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int s;
public:
    KthLargest(int k, vector<int>& nums) {
        s=k;
        for(auto num: nums) pq.push(num);
        while(pq.size()>s) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>s) pq.pop();
        return pq.top();
    }
};