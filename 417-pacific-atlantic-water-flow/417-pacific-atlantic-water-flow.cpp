class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(int i, int j, vector<vector<int>>& a, int prev, vector<vector<int>>& o) {
        if(i < 0 || j < 0 || i >= a.size() || j >= a[0].size()) {
            return;
        }
        if(o[i][j] == 1 || a[i][j] < prev) {
            return;
        }
        o[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            dfs(i + dx[k], j + dy[k], a, a[i][j], o);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        if(n < 1) return {{}};
        
        vector<vector<int>> p(n, vector<int>(m,0)),al(n, vector<int>(m,0));
        
        for(int i = 0; i < m; i++) {
            dfs(0,i,a,INT_MIN,p);
            dfs(n-1,i,a,INT_MIN,al);
        }
        for(int i = 0; i < n; i++) {
            dfs(i,0,a,INT_MIN,p);
            dfs(i,m-1,a,INT_MIN,al);
        }
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(al[i][j] == 1 and p[i][j] == 1) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
        
};