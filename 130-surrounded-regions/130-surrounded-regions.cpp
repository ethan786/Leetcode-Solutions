class Solution {
public:
    
    // instead of marking surrounded region we can mark the boundry region
    
    void dfs(int i, int j, int n, int m , vector<vector<char>>& a) {
        a[i][j] = '*';
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        for(int x = 0; x < 4; ++x) {
            int ci = i + dx[x];
            int cj = j + dy[x];
            if(ci >= 0 and cj >= 0 and ci < n and cj < m and a[ci][cj] == 'O') {
                dfs(ci,cj,n,m,a);
            }
        }
    }
    
    void solve(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(a[i][j] == 'O') {
                        dfs(i,j,n,m,a);
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == 'O') {
                   a[i][j] = 'X';
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == '*') {
                   a[i][j] = 'O';
                }
            }
        } 
        
    }
};