class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = string(s.rbegin(),s.rend());
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    dp[i][j] = 0;
                }else{
                    if(s[i-1]==s2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[n][n];
    }
};