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
        vector<vector<int>> dp(301,vector<int>(5001,-1));
        return solve(a,c,0,dp);
    }
};