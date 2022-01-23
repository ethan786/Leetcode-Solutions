class Solution {
public:
       
    int solve(int i,int n,int c,vector<int>& coins, int amount,vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        
        if(amount < 0){
            return INT_MAX-1;
        }
        if(i >= n){
            return INT_MAX-1;
        }
        if(dp[amount][i]!=-1) return dp[amount][i];
        if(dp[amount][i] !=-1) return dp[amount][i] ;
        return dp[amount][i] = min({solve(i,n,c+1,coins,amount-coins[i],dp)+1,
        solve(i+1,n,c,coins,amount,dp)});
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        int ans = solve(0,n,0,coins,amount,dp); 
        return ans == INT_MAX-1 ? -1 : ans;
        
    }
    
//     int solve(int n,vector<int>& coins, int amount,vector<vector<int>> &dp){
//         if(n==0 || amount == 0){
//             return amount == 0 ? 0 : INT_MAX-1;
//         }
//         if(amount < 0) return 0;
//         if(dp[amount][n-1]!=-1) return dp[amount][n-1]; 
//         if(coins[n-1] > amount){
//             return solve(n-1,coins,amount,dp)+0;
//         }else{
//             return dp[amount][n-1] = min(solve(n-1,coins,amount,dp)+0,1+solve(n,coins,amount-coins[n-1],dp));
//         }
//     }
    
//     int coinChange(vector<int>& coins, int amount) 
//     {
//         int n = coins.size();
//         vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
//         int ans = solve(n,coins,amount,dp); 
//         return ans == INT_MAX-1 ? -1 : ans;
        
//     }
    
    
};