class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i, vector<int> &a,vector<int> &v, int k) {
        if(i == a.size()) {
            if(v.size() == k) {
                ans.push_back(v);
            }
            return;
        }
        
        v.push_back(a[i]);
        solve(i+1,a,v,k);
        v.pop_back();
        solve(i+1,a,v,k);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = i+1;
        }
        solve(0,a,v,k);
        return ans;
    }
};