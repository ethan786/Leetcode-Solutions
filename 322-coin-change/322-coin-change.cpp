class Solution {
public:
    int solve(int i, vector<int> &a, int t, vector<vector<int>> &dp) {
        if(i == a.size()){
            if(t == 0) {
                return 0;
            }
            return INT_MAX-10;
        }
        
        if(dp[i][t] != -1) {
            return dp[i][t];
        }
        
        int op1 = INT_MAX;
        if(t >= a[i]) {
            op1 = 1 + solve(i,a,t-a[i],dp);
        }
        int op2 = solve(i+1,a,t,dp);
        return dp[i][t] = min(op1,op2);
    }
    
    int coinChange(vector<int>& a, int t) {
        vector<vector<int>> dp(a.size() + 1,vector<int>(t+1,-1));
        int ans = solve(0,a,t,dp);
        int mx = (ans == INT_MAX - 10) ? -1 : ans; 
        return mx;
    }
};