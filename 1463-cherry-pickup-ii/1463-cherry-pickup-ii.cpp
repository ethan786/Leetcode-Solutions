class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>> &a, vector<vector<vector<int>>> &dp) {
        if(j1 < 0 || j1 >= a[0].size() || j2 < 0 || j2 >= a[0].size()) return -1e8;
        if(i == a.size() - 1) {
            if(j1 == j2) return a[i][j1];
            return a[i][j1] + a[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int ans = 0;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int val = 0;
                if(j1 == j2) val = a[i][j1];
                else val = a[i][j1] + a[i][j2];
                val += solve(i+1,j1+dj1,j2+dj2,a,dp);
                ans = max(ans, val);
            }
        }
            
        return dp[i][j1][j2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0,0,m-1,a,dp);
    }
};