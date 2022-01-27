class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        //base case
        for(int i=0;i<m;i++){
            dp[0][i] = v[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int leftup = INT_MAX;
                if(j>0){
                 leftup = dp[i-1][j-1];
                }
                int up = dp[i-1][j];
                int rightup = INT_MAX;
                if(j+1<m){
                 rightup = dp[i-1][j+1];
                }
                dp[i][j] = v[i][j] + min({leftup,up,rightup});
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};