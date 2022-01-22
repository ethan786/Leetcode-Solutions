class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    
        int n=cost.size();
        vector<int> dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            int op1 = dp[i-1];
            int op2 = dp[i-2];
            dp[i] = min(op1,op2) + cost[i];
        }
        return min(dp[n-1],dp[n-2]);
                                                
        
    }
};

//dp[i] -> min cost to reach ith point