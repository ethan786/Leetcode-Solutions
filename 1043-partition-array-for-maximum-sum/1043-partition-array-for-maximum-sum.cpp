class Solution {
public:
    int dp[501];
    int solve(int i, vector<int> &a, int k) {
        if(i == a.size()) {
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int mx = INT_MIN, len = 0, ans = -1;
        
        for(int j = i; j < min(i+k,(int)a.size()); j++) {
            len++;
            mx = max(mx,a[j]);
            int sum = mx * len + solve(j+1,a,k);
            ans = max(ans,sum);
        }
        
        return dp[i] = ans;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,a,k);
    }
};