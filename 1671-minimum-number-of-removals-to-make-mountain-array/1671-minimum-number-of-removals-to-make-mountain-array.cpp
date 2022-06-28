class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,1);
        int ans1 = 1, ans2 = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(a[i] > a[j] and dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        vector<int> dp2(n,1);
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(a[i] > a[j] and dp2[i] < dp2[j] + 1) {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }
        int maxi = -1;
        
        for(int i = 0; i < n; i++) {
            if(dp[i] > 1 and dp2[i] > 1)
                maxi = max(maxi, dp[i] + dp2[i]);
        }
        
        return n + 1 - maxi;
    }
};