class Solution {
public:
    //recursion
//     int solve(int i,vector<int>& nums,int r){
//         if(i == nums.size()){
//             if(r == 0){
//                 return 0;
//             }
//             return -1000000;
//         }
        
//         int op1 = nums[i] + solve(i+1,nums,(r+nums[i])%3);
//         int op2 = solve(i+1,nums,r);
//         return max(op1,op2);
//     }
    //recurison + memo
    int solve(int i,vector<int>& nums,int r,vector<vector<int>> &dp){
        if(i == nums.size()){
            if(r == 0){
                return 0;
            }
            return -1000000;
        }
        if(dp[i][r] != -1) return dp[i][r];
        
        int op1 = nums[i] + solve(i+1,nums,(r+nums[i])%3,dp);
        int op2 = solve(i+1,nums,r,dp);
        return dp[i][r] = max(op1,op2);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        
        return solve(0,nums,0,dp);
//         vector<vector<int>> dp(n,vector<int>(3,0));
//         if(nums[0]%3 == 0){
//             dp[0][0] = nums[0];
//         }else if(nums[0]%3 == 1){
//             dp[0][1] = nums[0];
//         }else{
//             dp[0][1] = nums[0];
//         }
//         for(int i=1;i<n;i++){
//             int x = dp[i-1][0] + nums[i];
//             int y = dp[i-1][1] + nums[i];
//             int z = dp[i-1][2] + nums[i];
//             dp[i] = dp[i-1];
//             // cout<<x<<" "<<y<<" "<<z<<endl;
//             dp[i][x%3] = max({dp[i][x%3],x});
//             dp[i][y%3] = max({dp[i][y%3],y});
//             dp[i][z%3] = max({dp[i][z%3],z});
            
//         }
//         return dp[n-1][0];
    }
};