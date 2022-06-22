class Solution {
public:
    
    long long solve(int i,vector<vector<int>> &a, vector<long long> &dp) {
        if(i >= a.size()) {
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        long long take = a[i][0] + solve(i+1+a[i][1],a,dp);
        long long nottake = solve(i+1,a,dp);
        
        return dp[i] = max(take,nottake);
    }
    
    long long mostPoints(vector<vector<int>>& a) {
        vector<long long> dp(a.size(),-1);
        return solve(0,a,dp);
    }
};