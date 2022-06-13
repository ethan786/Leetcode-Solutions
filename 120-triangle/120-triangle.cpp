class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        if(n == 1) return a[0][0];
        
        for(int i = 0; i < a[n-1].size(); i++) {
            dp[n-1][i] = a[n-1][i];
        }
        
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < a[i].size(); j++) {
                dp[i][j] = a[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
        
    }
};

