class Solution {
public:
    int maximumProduct(vector<int>& a, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = a.size();
        for(int i=0;i<n;i++){
            pq.push(a[i]);
        }
        while(k--){
            int t = pq.top();
            pq.pop();
            t++;
            pq.push(t);
        }
        int m = 1e9+7;
        long long ans = 1;
        while(!pq.empty()){
            ans *= pq.top();
            ans %= m;
            pq.pop();
        }
        return ans;
    }
};