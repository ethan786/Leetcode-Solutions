class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

// 2 5 1 2 5
// 10 5 2 1 5 2