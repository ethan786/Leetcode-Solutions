class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    
        int n=cost.size();
        //vector<int> dp(n+1);
        int a =cost[0];
        int b =cost[1];
        for(int i=2;i<n;i++){
            int c = min(a,b) + cost[i];
            a = b;
            b = c;
        }
        return min(a,b);
                                                
        
    }
};

//dp[i] -> min cost to reach ith point