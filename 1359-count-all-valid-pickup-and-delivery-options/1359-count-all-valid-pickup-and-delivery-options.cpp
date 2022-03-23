class Solution {
public:
    
    const int m  = 1e9 + 7;
    
    int countOrders(int n) {
        vector<long long> dp(501);
        dp[1] = 1;
        dp[2] = 6;
        for(int i=3;i<=n;i++){
            int x = (2*i) - 1;
            int sum  = (x*(x+1))/2;
            dp[i] = (dp[i-1] * sum) % m;
        }
        return dp[n];
    }
};