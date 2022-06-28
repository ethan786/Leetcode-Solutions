class Solution {
public:
    
    int solve(int i, vector<int> &a, int lane, vector<vector<int>> &dp) {
        if(i == a.size()-1) {
            return 0;
        }
        if(a[i] == lane) {
            return INT_MAX-100;
        }
        
        if(dp[i][lane] != -1) return dp[i][lane];
        
        if(a[i+1] == lane) {
            return dp[i][lane] = min(1 + solve(i,a,(lane+1)%3,dp), 1 + solve(i,a,(lane+2)%3,dp));
        }
        return dp[i][lane] = solve(i+1,a,lane,dp);        
    }
    
    int minSideJumps(vector<int>& a) {
        for(auto &i : a) {
            i--;
        }
        vector<vector<int>> dp(a.size()+1,vector<int>(3,-1));
        return solve(0,a,1,dp);
    }
};
// int help(int lane,int i,vector<int>&ob,vector<vector<int>>& dp)
//     {
        
//         if(i==n-1)
//             return 0;
//         if(ob[i]==lane+1)
//             return INT_MAX;
//         if(dp[i][lane]!=-1)
//             return dp[i][lane];
//         if(ob[i+1]!=lane+1)
//             return dp[i][lane]=help(lane,i+1,ob,dp);
//         return dp[i][lane]=1+min(help((lane+1)%3,i,ob,dp),help((lane+2)%3,i,ob,dp));
//     }
//     int minSideJumps(vector<int>& obstacles) {
//         n=obstacles.size();
//         vector<vector<int>>dp(n+1,vector<int>(3,-1));
//         return help(1,0,obstacles,dp);
        
//     }