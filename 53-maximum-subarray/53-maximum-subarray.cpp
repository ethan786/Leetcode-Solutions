class Solution {
public:
    //o(n^2) approach finding sum of all subarray 
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans = INT_MIN;
    //     for(int s=0;s<n;s++){
    //         for(int e=s;e<=n;e++){
    //             int sum=0;
    //             for(int k=s;k<e;k++){
    //                 sum+=nums[k];
    //                 ans = max(ans,sum);
    //             }
    //         }
    //     }
    //     return ans;
    // }
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int sum = 0;
        for(int i =0;i<n;i++){
            sum += nums[i];
            ans = max(sum,ans);
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
    
    //o(n) approach kadane's algorithm
    // int maxSubArray(vector<int>& nums) {
    //     int ans = INT_MIN;
    //     int n = nums.size();
    //     int sum = 0;
    //     for(int i =0;i<n;i++){
    //         sum += nums[i];
    //         ans = max(sum,ans);
    //         if(sum<0){
    //             sum=0;
    //         }
    //     }
    //     return ans;
    // }
};