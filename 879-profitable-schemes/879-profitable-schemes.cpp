class Solution {
public:
    int dp[102][102][102];
    int m = 1000000007;
    int solve(int i,int size,int n, int mp, vector<int>& g, vector<int>& p,int x,int y){
        if(i == size){
            if(n >= x and mp <= y){
                return 1;
            }
            return 0;
        }
        else if(x > n){
            return 0;
        }
        
        if(dp[i][x][y]!=-1) return dp[i][x][y];
        
        int op1 = solve(i+1,size,n,mp,g,p,x+g[i],min(y+p[i],mp));
        int op2 = solve(i+1,size,n,mp,g,p,x,y);
        int ans = (op1+op2)%m;
        dp[i][x][y] = ans%m;
        return ans%m;
    }
    
    int profitableSchemes(int n, int mp, vector<int>& g, vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        return solve(0,g.size(),n,mp,g,p,0,0);
    }
};