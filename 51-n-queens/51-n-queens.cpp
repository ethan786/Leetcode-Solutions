class Solution {
public:
    
    
    void solve(int n,vector<vector<string>> &ans, vector<string> &a, int c, vector<int>&l, vector<int>&ld, vector<int> &ud) {
        if(c == n) {
            ans.push_back(a);
            return;
        }
        
        for(int r = 0; r < n; r++) {
            if(l[r] == 0 and ld[(c-r) + n-1] == 0 and ud[c+r] == 0) {
                a[r][c] = 'Q';
                l[r] = 1;
                ld[(c-r) + n-1] = 1;
                ud[c+r] = 1;
                solve(n,ans,a,c+1,l,ld,ud);
                a[r][c] = '.';
                l[r] = 0;
                ld[(c-r) + n-1] = 0;
                ud[c+r] = 0;
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> a(n);
        for(int i=0;i<n;i++){
            a[i] = s;
        }
        vector<int> l(n,0);
        vector<int> ld(2*n-1,0);
        vector<int> ud(2*n-1,0);
        solve(n,ans,a,0,l,ld,ud);
        return ans;
    }
};