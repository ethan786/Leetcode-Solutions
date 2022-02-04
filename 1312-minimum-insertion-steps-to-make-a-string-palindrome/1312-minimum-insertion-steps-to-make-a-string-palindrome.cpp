class Solution {
public:
    
    int lcs(string &x,string &y){
        int n = x.size();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }else if(x[i-1] == y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    
    int minInsertions(string s) {
        string x = s;
        string y = string(s.rbegin(),s.rend());
        int lengthOfLCS = lcs(x,y);
        //cout<<lengthOfLCS;
        return  s.size() - lengthOfLCS;
    }
};


    