class Solution {
public:
    //recursion + memo
    // int solve(int i,int j,vector<vector<int>> &t,vector<vector<int>> &dp){
    //     if(i == t.size()-1){
    //         return t[i][j];
    //     }else if(j > t[i].size()-1){
    //         return INT_MAX;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     return dp[i][j] = t[i][j] + min(solve(i+1,j,t,dp),solve(i+1,j+1,t,dp));
    // }
    
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //base case
        for(int i=0;i<n;i++){
            dp[n-1][i] = t[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j] = t[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
};