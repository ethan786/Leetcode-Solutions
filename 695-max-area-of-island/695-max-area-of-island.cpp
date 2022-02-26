class Solution {
public:
    int c = 0;
    void dfs(int i,int j,vector<vector<int>>& g,int n,int m){
        if(i < 0 || j < 0 || i > n-1 || j > m-1){
            return;
        }
        if(g[i][j] != 1){
            return;
        }
        g[i][j] = 2;
        c++;
        dfs(i+1,j,g,n,m);
        dfs(i,j-1,g,n,m);
        dfs(i-1,j,g,n,m);
        dfs(i,j+1,g,n,m);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == 1){
                    //cout<<"X";
                    dfs(i,j,g,n,m);
                    mx = max(c,mx);
                    c=0;
                }
            }
        }
        return mx;
    }
};