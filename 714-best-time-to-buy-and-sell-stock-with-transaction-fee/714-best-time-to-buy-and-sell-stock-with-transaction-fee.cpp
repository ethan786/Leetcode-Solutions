class Solution {
public:
    int fees;
    
    int solve(int i, vector<int> &a, bool buy, vector<vector<int>> &dp) {
        if(i >= a.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        
        if(buy) {
            return dp[i][buy] = max(-a[i] + solve(i+1,a,false,dp), 0 + solve(i+1,a,true,dp));
        }else {
            return dp[i][buy] = max(a[i] + solve(i+1,a,true,dp) - fees, 0 + solve(i+1,a,false,dp));
        }
    }
    
    int maxProfit(vector<int>& a, int fee) {
        fees = fee;
        int n = a.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return solve(0,a,true,dp);
    }
};