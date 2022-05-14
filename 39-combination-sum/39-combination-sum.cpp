class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(int i, vector<int> &a,vector<int> &v, int t){
        if(t < 0) return;
        if(i >= a.size()){
            if(t == 0){
                ans.push_back(v);
            }
            return;
        }
        // if(a[i] <= t) {
            v.push_back(a[i]);
            solve(i,a,v,t-a[i]);
            v.pop_back();
        // }
        solve(i+1,a,v,t);
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<int> v;
        solve(0,a,v,t);
        return ans;
    }
};