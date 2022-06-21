class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(int i, vector<int> &a) {
        if(i == a.size()) {
            ans.push_back(a);
        }
        
        for(int ind = i; ind < a.size(); ind++) {
            swap(a[i],a[ind]);
            solve(i+1,a);
            swap(a[i],a[ind]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        solve(0,a);
        return ans;
    }
};
