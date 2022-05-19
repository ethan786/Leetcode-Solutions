class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    void dfs(int i, int j, vector<vector<int>>& a,int color, int nc) {
        if(i < 0 || j < 0 || i > a.size()-1 || j > a[0].size()-1) return;
        
        if(a[i][j] != color || a[i][j] == nc) return;
        
        a[i][j] = nc;
        
        for(int x = 0; x < 4; x++) {
            dfs(i+dx[x],j+dy[x],a,color,nc);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& a, int r, int c, int nc) {
        int color = a[r][c];
        dfs(r,c,a,color,nc);
        return a;
    }
};