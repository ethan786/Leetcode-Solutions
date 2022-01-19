class Solution {
public:
    //recursion
//     int solve(int i,int n,vector<int> &nums){
//         if(i>=n) return 0;
//         int op1 = nums[i] + solve(i+2,n,nums);
//         int op2 = solve(i+1,n,nums);
//         return max(op1,op2);
//     }
    
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int ans1 = solve(0,n-1,nums);
//         int ans2 = solve(1,n,nums);
//         return max(ans1,ans2);
//     }
    //memo
    int solve(int i,int n,vector<int> &nums,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int op1 = nums[i] + solve(i+2,n,nums,dp);
        int op2 = solve(i+1,n,nums,dp);
        return dp[i] = max(op1,op2);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp(n+1,-1);
        int ans1 = solve(0,n-1,nums,dp);
        for(int i=0;i<=n;i++) dp[i]=-1;
        int ans2 = solve(1,n,nums,dp);
        return max(ans1,ans2);
    }
};