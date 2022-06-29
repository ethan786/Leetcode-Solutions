class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int n, int p) {
        if(i > n) return 100005;
        if(i == n) return 0;
        if(dp[i][p] != -1) return dp[i][p];
        int copy = 10005;
        if(i != p)    
            copy = 1 + solve(i,n,i);
        int paste = 1 + solve(i+p,n,p);
        return dp[i][p] = min(copy, paste);
    }
    
    int minSteps(int n) {
        memset(dp,-1,sizeof(dp));
        if(n == 1) return 0;
        return 1 + solve(1,n,1);
    }
};