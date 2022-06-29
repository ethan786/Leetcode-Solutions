class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int gap = 0; gap < n; gap++) {
            for(int i = 0, j = gap; j < n; i++, j++) {
                if(gap == 0) {
                    dp[i][j] = 1;
                }else if(gap == 1 and s[i] == s[j]) {
                    dp[i][j] = 1;
                }else if(gap > 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

