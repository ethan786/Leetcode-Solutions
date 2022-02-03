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
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return lcs(text1,text2,text1.size(),text2.size(),dp);
    }
};