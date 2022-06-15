class Solution {
public:
    
    int ans = INT_MAX;
    
    void solve(int i, vector<int>& a, int k, vector<int> &v) {
        if(i == a.size()) {
            ans = min(ans, *max_element(v.begin(), v.end()));
            return;
        }
        for(int j = 0; j < k; j++) {
            v[j] += a[i];
            solve(i+1,a,k,v);
            v[j]-=a[i];
        }
        
    }
    
    int distributeCookies(vector<int>& a, int k) {
        vector<int> v(k,0);
        solve(0,a,k,v);
        return ans;
    }
};