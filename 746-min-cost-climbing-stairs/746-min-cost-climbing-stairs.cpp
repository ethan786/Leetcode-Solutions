class Solution {
public:
    
    int solve(int n,vector<int> &cost,vector<int> &v){
        if(n>=cost.size()) return 0;
        if(v[n]!=-1) return v[n];
        int op1 = solve(n+1,cost,v);
        int op2 = solve(n+2,cost,v);
        
        return v[n] = min(op1,op2)+cost[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int x = cost.size();
        vector<int> v(x+1,-1);
        return min(solve(0,cost,v),solve(1,cost,v));
    }
};