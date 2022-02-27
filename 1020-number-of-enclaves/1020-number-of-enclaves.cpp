class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfsMarkZeroAllBoundryConnectedComponents(int i,int j,vector<vector<int>>& g,int n,int m){
        if(i < 0 || j < 0 || i > n-1 || j > m-1){
            return;
        }
        if(g[i][j] != 1){
            return;
        }
        g[i][j] = 0;
        for(int k=0;k<4;k++){
            dfsMarkZeroAllBoundryConnectedComponents(i+dx[k],j+dy[k],g,n,m);
        }
    }
    
    int numEnclaves(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int c = 0;
        for(int i=0;i<n;i++){
            if(g[i][0] == 1){
                dfsMarkZeroAllBoundryConnectedComponents(i,0,g,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(g[0][i] == 1){
                dfsMarkZeroAllBoundryConnectedComponents(0,i,g,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(g[i][m-1] == 1){
                dfsMarkZeroAllBoundryConnectedComponents(i,m-1,g,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(g[n-1][i] == 1){
                dfsMarkZeroAllBoundryConnectedComponents(n-1,i,g,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == 1){
                    c++;
                }
            }
        }
        return c;
    }
};