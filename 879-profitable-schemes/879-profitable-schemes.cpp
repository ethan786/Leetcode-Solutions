class Solution {
public:
    int dp[101][101][101];
    int solve(int i,int n, int mp, vector<int>& g, vector<int>& p){
        if(n<0){
            return 0;
        }
        if(i == p.size()){
            if(mp == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[i][n][mp] != -1) return dp[i][n][mp];
        
        int op1 = solve(i+1,n-g[i],max(0,mp-p[i]),g,p);
        int op2 = solve(i+1,n,mp,g,p);
        int ans = (op1+op2)%1000000007;
        dp[i][n][mp] = ans;
        return ans ;
    }
    
    int profitableSchemes(int n, int mp, vector<int>& g, vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,mp,g,p);
    }
};