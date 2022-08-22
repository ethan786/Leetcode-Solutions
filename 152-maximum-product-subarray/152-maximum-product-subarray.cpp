class Solution {
public:
    int maxProduct(vector<int>& a) {
        int mx = a[0], mi = a[0], ans = a[0];
        for(int i = 1; i < a.size(); i++) {
            if(a[i] < 0) swap(mx,mi);
            mx = max(a[i], a[i] * mx);
            mi = min(a[i], a[i] * mi);
            ans = max({ans, mx});
        }
        return ans;
    }
    
// int maxProduct(vector<int>& nums) {
        
//         int n = nums.size();
//         int ans = nums[0];
//         int ma = ans;
//         int mi = ans;
        
//         for(int i=1;i<n;i++){
//             if(nums[i]<0){
//                 swap(ma,mi);
//             }
//             ma = max(nums[i],ma*nums[i]);
//             mi = min(nums[i],mi*nums[i]);
//             ans = max(ans,ma);
//         }
        
        
//         return ans;
//     }
};