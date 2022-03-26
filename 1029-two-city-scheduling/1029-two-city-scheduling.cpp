class Solution {
public:
    int solve(int i, vector<vector<int>>& a, int A,int B,vector<vector<int>> &dp){
        if(i == a.size() and !A and !B){
            return 0;
        }
        if(dp[A][B] != INT_MAX) return dp[A][B];
        int op1 = INT_MAX, op2 = INT_MAX;
        if(A > 0){
            op1 = a[i][0] + solve(i+1,a,A-1,B,dp);
        }
        if(B > 0){
            op2 = a[i][1] + solve(i+1,a,A,B-1,dp);
        }
        return dp[A][B] = min(op1,op2);
        
    }
    
    int twoCitySchedCost(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        return solve(0,a,n/2,n/2,dp);
    }
};
// class Solution {
// public:
//    //Top-Down Dp(recoursion with memorization)
//     int findMinValUsingDP(vector<vector<int>>& costs,int X,int Y,int T,vector<vector<int>>&dp){
//         if(costs.size()==T&&!X&&!Y)return 0;
//         if(dp[X][Y]!=INT_MAX)return dp[X][Y];
//         int minVal = INT_MAX;
//         if(X)
//             minVal = costs[T][0]+findMinValUsingDP(costs,X-1,Y,T+1,dp);
//         if(Y)
//             minVal = min(minVal,costs[T][1]+findMinValUsingDP(costs,X,Y-1,T+1,dp));
//         return dp [X][Y] = minVal;
//     }
//     int twoCitySchedCost(vector<vector<int>>& costs){
//         vector<vector<int>>dp(costs.size(),vector<int>(costs.size(),INT_MAX));
//         return findMinValUsingDP(costs,costs.size()/2,costs.size()/2,0,dp);
//     }
// };