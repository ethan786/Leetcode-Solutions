class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i, vector<int> &a, vector<int> &v, int t) {
        
        if(t < 0) return;
        if(t == 0) {
            ans.push_back(v);
            return;
        }
        
        for(int ind = i; ind < a.size(); ind++) {
            if(ind != i and a[ind] == a[ind-1]) continue;
            t -= a[ind];
            v.push_back(a[ind]);
            solve(ind+1,a,v,t);
            v.pop_back();
            t += a[ind];
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        vector<int> v;
        solve(0,a,v,t);
        return ans;
    }
};