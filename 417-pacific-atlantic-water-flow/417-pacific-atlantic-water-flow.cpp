class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    void solve(int i, int j, vector<vector<int>> &x, vector<vector<int>> &a, int p) {
        if(min(i,j) < 0 || i >= a.size() || j >= a[0].size() || a[i][j] < p || x[i][j] == 1) return;
        x[i][j] = 1;
        // cout<<i<<" "<<j<<endl;
        for(int k = 0; k < 4; k++) {
            int ci = i + dx[k], cj = j + dy[k];
            solve(ci,cj,x,a,a[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> x(n,vector<int>(m,0)), y(n,vector<int>(m,0));
        for(int i = 0; i < n; i++) {
            solve(i,0,x,a,-1);
            solve(i,m-1,y,a,-1);
        }
        for(int i = 0; i < m; i++) {
            solve(0,i,x,a,-1);
            solve(n-1,i,y,a,-1);
        }
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(x[i][j] == 1 and y[i][j] == 1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};