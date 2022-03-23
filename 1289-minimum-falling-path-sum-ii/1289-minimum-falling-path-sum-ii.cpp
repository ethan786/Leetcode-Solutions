class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++){
            dp[0][i] = g[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int mx = INT_MAX;
                for(int k=0;k<m;k++){
                    
                    if(k == j) continue;
                    mx = min(mx,dp[i-1][k]);
                }
                dp[i][j] = g[i][j] + mx;
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<m;i++){
            ans = min(ans,dp[n-1][i]);
        }
        
        return ans;

    }
};

