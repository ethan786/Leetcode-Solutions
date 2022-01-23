class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        if(n == 1){
            return dp[0];
        }
        for(int i=1;i<n;i++){
            dp[i] = 1;
            for(int j=i-1;j>=0;j--){
                if(nums[j] >= nums[i]) continue;
                int possibleAns = dp[j] + 1;
                if(possibleAns > dp[i]){
                    dp[i] = possibleAns;
                }
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            ans = max(dp[i],ans);
        }
        return ans;
    }
};