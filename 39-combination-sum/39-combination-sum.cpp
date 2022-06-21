class Solution {
public:
    
    set<vector<int>> s;
    
    void solve(int i, vector<int> &a, int t,vector<int> &v) {
        if(t < 0) return;
        if(a.size() == i) {
            if(t == 0) {
                s.insert(v);
            }
            return;
        }
        t -= a[i];
        v.push_back(a[i]);
        solve(i,a,t,v);
        v.pop_back();
        t += a[i];
        solve(i+1,a,t,v);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,a,t,v);
        for(auto &i : s) ans.push_back(i);
        return ans;
    }
};