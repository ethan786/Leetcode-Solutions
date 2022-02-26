class Solution {
public:
    
    bool dfs(int i,int j,vector<vector<int>>& g,int n,int m){
        if(i < 0 || j < 0 || i > n-1 || j > m-1){
            return false;
        }
        if(g[i][j] == 1) return true;
        g[i][j] = 1;
        bool a = dfs(i+1,j,g,n,m);
        bool b = dfs(i,j-1,g,n,m);
        bool c = dfs(i,j+1,g,n,m);
        bool d = dfs(i-1,j,g,n,m);
        return a and b and c and d;
    }
    
    int closedIsland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int c = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == 0){
                    if(dfs(i,j,g,n,m)){
                        c++;
                    }
                }
            }
        }
        return c;
    }
};
