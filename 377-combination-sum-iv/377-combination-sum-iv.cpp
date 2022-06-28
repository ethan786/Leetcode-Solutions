class Solution {
public:
    int dp[1001];
    int solve(vector<int> &a, int t) {
        if(t == 0) return 1;
        if(dp[t] != -1) return dp[t];
        dp[t] = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] <= t) dp[t] += solve(a,t-a[i]); 
        }
        return dp[t];
    }
    
    int combinationSum4(vector<int>& a, int t) {
        int n = a.size();
        memset(dp,-1,sizeof(dp));
        return solve(a,t);
        
    }
};
