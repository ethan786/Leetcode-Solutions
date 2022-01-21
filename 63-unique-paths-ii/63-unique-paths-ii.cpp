class Solution {
public:
    // recursion + memo
    int path(vector<vector<int>>& obstacleGrid,int n,int m,int i,int j,vector<vector<int>> &dp){
        if(i==n-1 and j == m-1 and obstacleGrid[i][j] == 0){
            return 1;
        }else if(i>=n || j>=m || obstacleGrid[i][j] == 1 ){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j] = path(obstacleGrid,n,m,i+1,j,dp) + path(obstacleGrid,n,m,i,j+1,dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int dp[n][m];
        if(obstacleGrid[0][0] == 1){
            cout<<"s";
            return 0;
        }
        dp[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0){ 
                    dp[i][j] = 1;
                }else if(obstacleGrid[i][j]){
                    dp[i][j] = 0;
                }else{
                    int up=0,l=0;
                    if(i>0) up = dp[i-1][j]; 
                    if(j>0) l = dp[i][j-1];
                    dp[i][j] = up+l;
                }
            }
        }
        return dp[n-1][m-1];
    }
};