class Solution {
public:
     int dfs(vector<vector<int>>& a,int m,int n,vector<vector<int>>&dp,int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i-1>=0 && a[i-1][j]>a[i][j])
            dp[i][j]=max(dp[i][j],1+dfs(a,m,n,dp,i-1,j));
        
        if(j-1>=0 && a[i][j-1]>a[i][j])
            dp[i][j]=max(dp[i][j],1+dfs(a,m,n,dp,i,j-1));
        
        if(i+1<m && a[i+1][j]>a[i][j])
            dp[i][j]=max(dp[i][j],1+dfs(a,m,n,dp,i+1,j));
        
        if(j+1<n && a[i][j+1]>a[i][j])
            dp[i][j]=max(dp[i][j],1+dfs(a,m,n,dp,i,j+1));
        
        dp[i][j]=max(dp[i][j],1);
        return dp[i][j];

    }
    
    int longestIncreasingPath(vector<vector<int>>& a) {
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int i,j,ans=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                dp[i][j]=dfs(a,m,n,dp,i,j);
                ans=max(ans,dp[i][j]);
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        return ans;
    }
};