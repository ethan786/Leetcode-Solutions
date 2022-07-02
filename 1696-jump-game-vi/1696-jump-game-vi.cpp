class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int n = a.size();
        if(n == 1) return a[0];
        vector<int> dp(n+1,0);
        dp[0] = a[0];
        multiset<int> s;
        s.insert(dp[0]);
        for(int i = 1; i <= min(k,n); i++) {
            dp[i] = a[i] + *prev(s.end());
            s.insert(dp[i]);
        }
        
        for(int i = k+1, j = 0; i < n; i++, j++) {
            s.erase(s.find(dp[j]));
            dp[i] = a[i] + (empty(s) ? 0 :*prev(s.end()));
            s.insert(dp[i]);
        }
        return dp[n-1];
    }
};