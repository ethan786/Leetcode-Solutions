class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> l(n),r(n);
        l[0] = a[0];
        for(int i=1;i<n;i++){
            l[i] = max(l[i-1],a[i]);
        }
        r[n-1] = a[n-1];
        for(int i = n-2;i>=0;i--){
            r[i] = max(r[i+1],a[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += (min(l[i],r[i]) - a[i]) < 0 ? 0 : min(l[i],r[i]) - a[i];
        }
        return ans;
    }
};