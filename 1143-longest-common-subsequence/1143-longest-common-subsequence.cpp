class Solution {
public:
    
    int lcs(string &x,string &y,int n,int m,vector<vector<int>>& dp){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n-1][m-1] != -1) return dp[n-1][m-1];
        if(x[n-1] == y[m-1]){
            return 1 + lcs(x,y,n-1,m-1,dp);
        }
        return dp[n-1][m-1] = max(lcs(x,y,n-1,m,dp),lcs(x,y,n,m-1,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n  = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(text2.size()+1,0));
        //base case
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    dp[i][j] = 0;
                }else if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        return dp[n][m];
    }
};