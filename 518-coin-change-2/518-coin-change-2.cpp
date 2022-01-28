class Solution {
public:
    
    int solve(int a,vector<int>& c,int i,vector<vector<int>>& dp){
        if(a == 0 and i == c.size()){
            return 1;
        }
        if(a < 0 || i>= c.size()){
            return 0;
        }
        if(dp[i][a] != -1) return dp[i][a];
        int op1 = solve(a-c[i],c,i,dp) ;
        int op2 = solve(a,c,i+1,dp);
        //int op3 = solve(a-c[i],c,i+1);
        return dp[i][a] = op1+op2;
    }
    
    int change(int a, vector<int>& c) {
        vector<vector<int>> dp(c.size()+2,vector<int>(a+2,0));
        
        for(int i=0;i<c.size()+1;i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=0;i<a+1;i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i=1;i<=c.size();i++){
            for(int j=1;j<=a;j++){
              if(c[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-c[i-1]];
                }
            }
        }
        return dp[c.size()][a];
    }
};