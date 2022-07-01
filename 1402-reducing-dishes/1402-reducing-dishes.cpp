class Solution {
public:
    int dp[502][502];
    int solve(int i, int s, vector<int> &a) {
        if(i == a.size()) return 0;
        if(dp[i][s] != -1) return dp[i][s];
        int take = a[i] * s + solve(i+1,s+1,a);
        int notake = solve(i+1,s,a);
        return dp[i][s] = max(take, notake);
    }
    
    int maxSatisfaction(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        sort(a.begin(),a.end());
        return solve(0,1,a);
    }
};