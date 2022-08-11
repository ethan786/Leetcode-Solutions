class Solution {
public:
    vector<int> dp;
    int fun(int n) {
        if(n == 0) return false;
        if(dp[n] != -1) return dp[n];
        for(int i = 1; i*i <= n; i++) {
            if(!fun(n-i*i)) return dp[n] = true;
        }
        return dp[n] = false;
    }
    
    bool winnerSquareGame(int n) {
        dp.resize(n+1,-1);
        return fun(n);
    }
};