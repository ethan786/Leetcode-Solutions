class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        dp[0] = 1;
        if(n==1) return 1;
        dp[1] = nums[0] < nums[1] ? 2 : 1;//ternary operator
        if(n==2) return max(dp[1],dp[0]);
        for(int i=2;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j] + 1,dp[i]);
                }
            }
        }
        int mx = -1e5;
        for(int i=0;i<n;i++){
            mx = max(dp[i],mx);
        }
        return mx;
    }
};