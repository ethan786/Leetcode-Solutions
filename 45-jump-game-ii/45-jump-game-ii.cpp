class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,0);
        
        for(int i = 1; i < n; i++) {
            int mi = INT_MAX;
            for(int j = i-1; j >= 0; j--) {
                if(i-j <= a[j])
                    mi = min(dp[j] + 1, mi);
            }
            dp[i] = mi;
        }
        return dp[n-1];
    }
};