class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        if(n < 4){
            return n;
        }
        int i = 2;
        map<int,int> mp;
        while(i*i <= n){
            dp[i*i] = 1;
            mp[i*i] = 1;
            i++;
        }
        dp[2] = 2;
        dp[3] = 3;
        for(int i=0;i<=n;i++){
            for(auto &j : mp){
                if(j.first < i)
                dp[i] = min(dp[i-j.first]+dp[j.first],dp[i]);
            }
        }
        return dp[n];
    }
};