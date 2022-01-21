class Solution {
public:
    
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
        vector<vector<int>> dp(101,vector<int>(101,-1));
        return path(obstacleGrid,n,m,0,0,dp);
    }
};