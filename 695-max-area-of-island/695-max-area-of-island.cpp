class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(int i, int j, vector<vector<int>> &a, int n, int m,int &area) {
        if(i < 0 || j < 0 || i > n-1 || j > m-1) return;
        if(a[i][j] != 1) return;
        a[i][j] = 2;
        area++;
        for(int x = 0; x < 4; ++x) {
            dfs(i+dx[x],j+dy[x],a,n,m,area);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& a) {
        int ans = 0;
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == 1) {
                    int area = 0;
                    dfs(i,j,a,n,m,area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};