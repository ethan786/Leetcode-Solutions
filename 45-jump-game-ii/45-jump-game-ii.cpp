class Solution {
public:
    
    int solve(vector<int>& nums,int i,vector<int> &dp){
        if(i>=nums.size()-1) return 0;
        int minJumps = INT_MAX-100000;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            minJumps = min(1+solve(nums,i+j,dp),minJumps);
        }
        return dp[i] = minJumps;
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};