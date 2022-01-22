class Solution {
public:
    int maxProfit(vector<int>& p) {
       int n = p.size();
        if(n==1){
            return 0;
        }
        if(n==2){
            return max(0,p[1]-p[0]);
        }
        vector<int> v(n);
        v[n-1] = p[n-1];
        int m = INT_MIN;
        for(int i=n-1;i>=0;i--){
            m = max(p[i],m);
            v[i] = m;
        }
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(v[i]-p[i],mx);
        }
        if(mx>0) return mx;
        else return 0;
    }
};