class Solution {
public:
    
    int mod = 1000000007; // 1e9 + 7
    int dp[51][51][51];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    int solve(int m, int n, int mx, int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0) return 1;
        if(mx == 0) return 0;
        if(dp[i][j][mx] != -1) return dp[i][j][mx];
        int ans = 0;
        
        for(int x = 0; x < 4; x++) {
            ans = (ans + solve(m,n,mx-1,i+dx[x],j+dy[x])) % mod;
        }
        return dp[i][j][mx] = ans;
    }
    
    int findPaths(int m, int n, int mx, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,mx,sr,sc);
    }
};