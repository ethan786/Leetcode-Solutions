class Solution {
public:
    
    int ans = 0;
    
    void solve(int i, vector<int>& a, int n, vector<bool>& vis){
        if(i == a.size()){
            ans++;
            return;
        }
        
        for(int j = 0; j < n; ++j) {
            if(!vis[j] and (a[j] % (i+1) == 0 || (i+1) % a[j] == 0)){
                vis[j] = true;
                solve(i+1,a,n,vis);
                vis[j] = false;
            }
        }
        
    }
    
    int countArrangement(int n) {
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            a[i] = i+1;
        }
        vector<bool> vis(n,false);
        solve(0,a,n,vis);
        return ans;
    }
};