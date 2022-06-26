class Solution {
public:
    int mod = 1000000007;
    long long solve(int i,int j,string &a,string &b,int n,int m,vector<vector<int>> &dp) {
        if(i == n and j == m) {
            return 1;
        }
        if(i > n || j > m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        long long x = 0;
        if(a[i] == b[j]) {
            x = solve(i+1,j+1,a,b,n,m,dp);
        }
        long long y = solve(i+1,j,a,b,n,m,dp);
        return dp[i][j] = (x + y) % mod;
    }

    int numDistinct(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int i = 0 ; i <= n; i++) dp[i][0] = 1; //b is empty
        for(int i = 1 ; i <= m; i++) dp[0][i] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    } 
};