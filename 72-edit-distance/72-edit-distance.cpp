class Solution {
public:
    //recursive way
//     int dp[501][501];
//     int solve(string &s1,string &s2,int n,int m){
//         //base case 
//         //if s1 --> empty return size of s2
//         if(n==0) return m;
//         //if s12 --> empty return size of s1
//         if(m==0) return n;
        
//         if(dp[n][m] != -1) return dp[n][m];
        
//         //if last char of s1 and s2 matches then we call for remaining string
//         int op1 = INT_MAX,op2 = INT_MAX;
//         if(s1[n-1] == s2[m-1]){
//             op1 = solve(s1,s2,n-1,m-1);
//         }else{
//             op2 = min({solve(s1,s2,n-1,m),solve(s1,s2,n-1,m-1),solve(s1,s2,n,m-1)}) + 1;
//         }
//         return dp[n][m] = min(op1,op2);
//     }
    
    int minDistance(string s1, string s2) {
        // memset(dp,-1,sizeof(dp));
        //return solve(s1,s2,s1.size(),s2.size());
        
        //tabulation
        int n = s1.size();
        int m = s2.size();
        if(n == 0) return m;
        if(m == 0) return n;
        int dp[n+1][m+1];
        for (int i=0;i<=n;i++) {
            for (int j=0;j<=m;j++) {
                dp[i][j] = 0;
            }
        }
        
        for (int i=0;i<=n;i++) {
            for (int j=0;j<=m;j++) {
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else{
                    if (s1[i-1] == s2[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = min({dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])}) + 1;
                    }
                }
            }
        }
        return dp[n][m];   
    }
};