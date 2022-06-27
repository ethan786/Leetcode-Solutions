class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 0; i <= m; i++) dp[0][i] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string s = "";
        int i = n, j = m;
        while(i > 0 and j > 0) {
            if(a[i-1] == b[j-1]) {
                s.push_back(a[i-1]);
                i--;j--;
            }else if(dp[i-1][j] > dp[i][j-1]) { 
                i--;
            }else  {
                j--;
            }
        }
        // cout<<s<<'\n';
        return dp[n][m];
    
    }
};