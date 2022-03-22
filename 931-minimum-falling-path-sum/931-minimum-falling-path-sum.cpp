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
                int op2 = INT_MAX, op3 = INT_MAX;
                int op1 = dp[i-1][j];
                if(j+1 < m){
                    op2 = dp[i-1][j+1];
                }
                if(j-1 >= 0){
                    op3 = dp[i-1][j-1];
                }
                dp[i][j] = g[i][j] + min({op1,op2,op3});
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<m;i++){
            ans = min(ans,dp[n-1][i]);
        }
        
        return ans;
    }
};