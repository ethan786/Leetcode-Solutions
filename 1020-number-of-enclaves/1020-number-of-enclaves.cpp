class Solution {
public:
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>& a) {
        a[i][j] = 0;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(int x = 0; x < 4; ++x) {
            int ci = i + dx[x];
            int cj = j + dy[x];
            if(ci < n and ci >= 0 and cj < m and cj >= 0 and a[ci][cj] == 1){
                dfs(ci,cj,n,m,a);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(a[i][j] == 1)
                        dfs(i,j,n,m,a);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(a[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};