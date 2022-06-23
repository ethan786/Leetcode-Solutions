class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 and j == 0) {
                    dp[i][j] = a[i][j];
                }else if(i == 0) {
                    dp[i][j] = a[i][j] + dp[i][j-1];
                }else if(j == 0){
                    dp[i][j] = a[i][j] + dp[i-1][j];
                }else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};