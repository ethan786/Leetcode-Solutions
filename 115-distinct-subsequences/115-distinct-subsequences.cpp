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
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return (int)solve(0,0,a,b,a.size(),b.size(),dp);
} 
};