class Solution {
public:
    
    int solve(int i,bool isBuy,int t,vector<int> &p,int n,vector<vector<int>> &dp){
        if(i>=n || t <= 0){
            return 0;
        }
        if(dp[i][isBuy] != -1){
            return dp[i][isBuy];
        }
        if(isBuy == false){
            int op1 = solve(i+1,!isBuy,t,p,n,dp) - p[i];
            int op2 = solve(i+1,isBuy,t,p,n,dp);
            //cout<<op1<<" "<<op2<<endl;
            return dp[i][isBuy] = max(op1,op2);
        }else{
            int op1 = solve(i+1,!isBuy,t-1,p,n,dp) + p[i];
            int op2 = solve(i+1,isBuy,t,p,n,dp);
            //cout<<op1<<" "<<op2<<"wwe"<<endl;
            return dp[i][isBuy] = max(op1,op2);
        }
    }
    
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if(n==1){
            return 0;
        }else if(n==2){
            return max(0,p[1]-p[0]);
        }
        bool isBuy = false;
        int trans = 1;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,isBuy,trans,p,n,dp);
    }
};