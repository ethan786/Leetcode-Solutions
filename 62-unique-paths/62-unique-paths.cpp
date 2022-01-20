class Solution {
public:
    int path(int n,int m,int i,int j,vector<vector<int>> &dp){
	if(i==n-1 and j==m-1){
		return 1;
	}
	if(i>n||j>m) return 0;
	//move forward
        
        if(dp[i][j]!=-1) return dp[i][j];
        
	int ans = path(n,m,i,j+1,dp) + path(n,m,i+1,j,dp);
	return dp[i][j] = ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(101,vector<int>(101,-1));
        return path(n,m,0,0,dp);
    }
};