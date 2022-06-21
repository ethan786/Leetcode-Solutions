class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(int i, vector<int> &a, vector<int> &v) {
        ans.push_back(v);
        for(int ind = i; ind < a.size(); ind++) {
            if(ind != i and a[ind] == a[ind-1]) continue;
            v.push_back(a[ind]);
            solve(ind+1,a,v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<int> v;
        solve(0,a,v);
        return ans;
    }
};