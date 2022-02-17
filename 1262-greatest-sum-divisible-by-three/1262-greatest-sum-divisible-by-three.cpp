class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        if(nums[0]%3 == 0){
            dp[0][0] = nums[0];
        }else if(nums[0]%3 == 1){
            dp[0][1] = nums[0];
        }else{
            dp[0][1] = nums[0];
        }
        for(int i=1;i<n;i++){
            int x = dp[i-1][0] + nums[i];
            int y = dp[i-1][1] + nums[i];
            int z = dp[i-1][2] + nums[i];
            dp[i] = dp[i-1];
            // cout<<x<<" "<<y<<" "<<z<<endl;
            dp[i][x%3] = max({dp[i][x%3],x});
            dp[i][y%3] = max({dp[i][y%3],y});
            dp[i][z%3] = max({dp[i][z%3],z});
            
        }
        return dp[n-1][0];
    }
};