class Solution {
public:
    bool isPossible(vector<int>& a) {
        int n = a.size();
        vector<int> one(n,1);
        priority_queue<long long> pq;
        
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            pq.push((long long)a[i]);
        }
        
        while(pq.top() != 1) {
            sum -= pq.top(); 
            if(sum == 0 || sum >= pq.top()) return false;
            int old = pq.top() % sum;
            
            if(sum != 1 and old  == 0) return false;
            
            pq.pop();
            pq.push(old);
            sum += old;
        }
        return true;
    }
};

// 1 1
// 1 2
// 3 2
// 3 5
// 8 5

// 9 3 5
// 1 3 5
// 1 3 1
// 1 1 1