class Solution {
public:
    int coinChange(vector<int>& a, int k) {
        vector<int> dp(k+1,0);
        sort(begin(a), end(a));
        for (int i = 1; i <= k; i++) {
            dp[i] = INT_MAX;
            for (int &c: a) {
                if(i-c < 0) break;
                if (dp[i - c] != INT_MAX) 
                    dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        // for(auto &i : dp) cout<<i<<endl;
        return dp[k] != INT_MAX ? dp[k] : -1;
    }
};

// 1 2 3 ... 11