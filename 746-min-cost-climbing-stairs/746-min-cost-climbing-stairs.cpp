class Solution {
public:
//     //recursion
//     int solve(int n,vector<int> &cost){
//         if(n>=cost.size()) return 0;
//         int op1 = solve(n+1,cost);
//         int op2 = solve(n+2,cost);
        
//         return min(op1,op2)+cost[n];
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
        
//         return min(solve(0,cost),solve(1,cost));
//     }
    // // memoziation
//     int solve(int n,vector<int> &cost,vector<int> &v){
//         if(n>=cost.size()) return 0;
//         if(v[n]!=-1) return v[n];
//         int op1 = solve(n+1,cost,v);
//         int op2 = solve(n+2,cost,v);
        
//         return v[n] = min(op1,op2)+cost[n];
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
//         int x = cost.size();
//         vector<int> v(x+1,-1);
//         return min(solve(0,cost,v),solve(1,cost,v));
//     }
    
    
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            vector<int> v(n,0);
            v[0] = cost[0];
            v[1] = cost[1];
            for(int i=2;i<n;i++){
                int op1 = v[i-1];
                int op2 = INT_MAX;
                if(i>1){
                op2 = v[i-2];
                }
                v[i] = min(op1,op2)+cost[i];
            }
            return min(v[n-1],v[n-2]);
    }
    
};