class Solution {
public:
//     //recursion
//     int solve(vector<int>& nums,int i,int n){
//         if(i>=n){
//             return 0;
//         }
//         int op1 = solve(nums,i+2,n) + nums[i];
//         int op2 = solve(nums,i+1,n);
//         return max(op1,op2);
//     }
    
//     int rob(vector<int>& nums) {
//         return solve(nums,0,nums.size());
//     }
    
       // memo
       int solve(vector<int>& nums,int i,int n,vector<int>& dp){
           if(i>=n){
               return 0;
           }
           if(dp[i]!=-1) return dp[i];
           int op1 = solve(nums,i+2,n,dp) + nums[i];
           int op2 = solve(nums,i+1,n,dp);
           return dp[i] = max(op1,op2);
       }
       int rob(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n+1,-1);
            return solve(nums,0,n,dp);
    }
};