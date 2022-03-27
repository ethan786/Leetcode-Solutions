class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>& g,int n,int m){
        if(i == n){
            return j;
        }
        if(g[i][j] == 1 and j == m-1){
            return -1;
        }
        if(g[i][j] == -1 and j == 0){
            return -1;
        }
        if(g[i][j] == 1 and j+1 < m and g[i][j] != g[i][j+1]){
            return -1;
        }else if(g[i][j] == -1 and j > 0 and g[i][j] != g[i][j-1]){
            return -1;
        }
        if(g[i][j] == 1){
            return solve(i+1,j+1,g,n,m);
        }else{
            return solve(i+1,j-1,g,n,m);
        }
    }
    
    vector<int> findBall(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<int> ans;
        for(int j=0;j<m;j++){
            ans.push_back(solve(0,j,g,n,m));
        }
        return ans;
    }
};
