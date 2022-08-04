class Solution {
public:
    long long appealSum(string s) {
        #define int int64_t
        int n = s.size();
        int ans = 0;
        vector<int> dp(n,1), last(26,-1);
        last[s[0]-'a'] = 0;
        for(int i = 1; i < n; i++) {
            dp[i] = dp[i-1] + (i - last[s[i]-'a']);
            last[s[i]-'a'] = i;
        }        
        for(auto &i : dp) {
            ans += i;
        }
        #undef int
        return ans;
    }
};