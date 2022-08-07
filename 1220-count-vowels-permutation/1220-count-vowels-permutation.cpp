class Solution {
public:
    int dp[20002][26];
    map<char, vector<char>> m;
    int mod = 1e9+7;
    int solve(int n, char pre) {
        if(n == 1) {
            return 1;
        }
        if(dp[n][pre - 'a'] != -1) return dp[n][pre - 'a'];
        int ans = 0;
        for(auto &i : m[pre]) {
            ans = (ans + solve(n-1, i)) % mod;
        }
        return dp[n][pre - 'a'] = ans % mod;
    }
    
    int countVowelPermutation(int n) {
        m['a'] = {'e'};
        m['e'] = {'a', 'i'};
        m['i'] = {'a', 'e', 'o', 'u'};
        m['o'] = {'i', 'u'};
        m['u'] = {'a'};
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(auto &ch : vowels) {
            ans = (ans + solve(n,ch)) % mod;
        }
        return ans % mod;
    }
};