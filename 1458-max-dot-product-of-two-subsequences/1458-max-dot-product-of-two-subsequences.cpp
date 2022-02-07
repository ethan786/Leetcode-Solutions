class Solution {
public:
    int dp[502][502];
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i==0 || j==0 ){
            return INT_MIN;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int op1 = nums1[i-1]*nums2[j-1] + max(0,solve(nums1,nums2,i-1,j-1));
        int op2 = solve(nums1,nums2,i,j-1);
        int op3 = solve(nums1,nums2,i-1,j);
        return dp[i][j] = max({op1,op2,op3});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,nums1.size(),nums2.size());
    }
};