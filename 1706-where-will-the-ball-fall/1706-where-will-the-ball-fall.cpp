class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>& g,int n,int m,vector<vector<int>> &dp){
        //ball fall out of at the bottom after dropping
        //the ball from the jth column at the top,
        if(i == n){
            return j;
        }
        
        if(dp[i][j] != -2){
            return dp[i][j];
        }
        
        //base case - 
        // if it's the corner of the board or
        // we stuck in a "V" shaped pattern 
        // between two boards
        if(g[i][j] == 1){
            if(j == m-1 || (j+1 < m and g[i][j] != g[i][j+1])){
                return -1;
            }
        }else if(g[i][j] == -1){
            if(j == 0 || (j > 0 and g[i][j] != g[i][j-1])){
                return -1;
            }
        }
        //Now if its possible to drop then move to left downwards or right downwards
        if(g[i][j] == 1){
            return dp[i][j] = solve(i+1,j+1,g,n,m,dp);
        }else{
            return dp[i][j] = solve(i+1,j-1,g,n,m,dp);
        }
    }
    
    vector<int> findBall(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        //memo
        vector<vector<int>> dp(n+1,vector<int>(m+1,-2));
        vector<int> ans;
        for(int j=0;j<m;j++){
            ans.push_back(solve(0,j,g,n,m,dp));
        }
        return ans;
    }
};
