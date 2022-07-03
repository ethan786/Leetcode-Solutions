class Solution {
public:
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    const int mod = 1000000007;
    int solve(int i,int j, int prev, vector<vector<int>>& a, vector<vector<long long>>& dp) {
        if(min(i,j) < 0 || i >= a.size() || j >= a[0].size()) return 0;
        if(a[i][j] <= prev) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long ans = 1;
        for(int x = 0; x < 4; x++) {
            ans += solve(i+dx[x],j+dy[x],a[i][j],a,dp);
        }
        return dp[i][j] = ans % mod;
    }
    
    int countPaths(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dp[i][j] == -1) {
                    dp[i][j] = (1 + solve(i+1,j,a[i][j],a,dp) + solve(i,j+1,a[i][j],a,dp) + solve(i,j-1,a[i][j],a,dp) + solve(i-1,j,a[i][j],a,dp)) % mod; 
                }
                ans = (ans + dp[i][j]) % mod;
            }
        }
        
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};