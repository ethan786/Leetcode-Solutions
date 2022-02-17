class Solution {
public:
    //recursion
    int solve(int i,vector<int>& nums,int r){
        if(i == nums.size()){
            if(r == 0){
                return 0;
            }
            return -1000000;
        }
        
        int op1 = nums[i] + solve(i+1,nums,(r+nums[i])%3);
        int op2 = solve(i+1,nums,r);
        return max(op1,op2);
    }
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
    //tabulation
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(1,vector<int>(3,0));
        if(nums[0]%3 == 0){
            dp[0][0] = nums[0];
        }else if(nums[0]%3 == 1){
            dp[0][1] = nums[0];
        }else{
            dp[0][1] = nums[0];
        }
        for(int i=1;i<n;i++){
            int x = dp[0][0] + nums[i];
            int y = dp[0][1] + nums[i];
            int z = dp[0][2] + nums[i];
            // cout<<x<<" "<<y<<" "<<z<<endl;
            dp[0][x%3] = max({dp[0][x%3],x});
            dp[0][y%3] = max({dp[0][y%3],y});
            dp[0][z%3] = max({dp[0][z%3],z});
            
        }
        return dp[0][0];
    }
};