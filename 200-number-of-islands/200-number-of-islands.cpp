class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>>& g,vector<vector<int>>& v,int n,int m){
        if(i < 0 || j < 0 || i > n-1 || j > m-1){
            return;
        }
        if(v[i][j] || g[i][j] != '1'){
            return;
        }
        v[i][j] = 1;
        dfs(i+1,j,g,v,n,m);
        dfs(i,j-1,g,v,n,m);
        dfs(i-1,j,g,v,n,m);
        dfs(i,j+1,g,v,n,m);
    }
    int c = 0;
    int numIslands(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    dfs(i,j,g,vis,n,m);
                    c++;
                }
            }
        }
        int co = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == '0'){
                    co++;
                }
            }
        }
        return c-co;
    }
};