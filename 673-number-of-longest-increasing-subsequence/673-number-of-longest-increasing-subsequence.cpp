class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size(), ans = 0;
    vector<int> dp(n,1), count(n,1);
    int mx = 1, c = 1;
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(a[i] > a[j] and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                count[i] = count[j];
            }else if(a[i] > a[j] and dp[i] == dp[j] + 1) {
                count[i] += count[j];
            }
        }
        mx = max(mx,dp[i]);
    }
    
    for(int i=0;i<n;i++) {
        if(dp[i] == mx) ans += count[i];
    }
    
    return ans;
    }
};