class Solution {
public:
//     Proof
// Lets consider 3 integers x, y, z. Where x<y<z. Now we need to add 1 to any of these integers and find which integers increment will lead to maximum product.

// x incremented	y incremented	z incremented
// (x+1)*y*z	x*(y+1)*z	x*y*(z+1)
// xyz + yz	xyz + xz	xyz + xy
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