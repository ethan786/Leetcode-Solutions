class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int>&c,int t,vector<int> &v){
        
        if(t<0) return;
        
        if(i == c.size()){
            if(t == 0){
                ans.push_back(v);
            }
            return;
        }
        t -= c[i];
        if(t >= 0){
        v.push_back(c[i]);
        solve(i,c,t,v);
        v.pop_back();
        }
        t += c[i];
        solve(i+1,c,t,v);
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> v;
        solve(0,c,t,v);
        return ans;
    }
};