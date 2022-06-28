class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        sort(a.begin(), a.end());
        
        int n = a.size();
        
        vector<int> dp(n,1), hash(n);
        int maxLen = 0, maxLenInd = 0;
        
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int j = i-1; j >= 0; j--) {
                if(a[i] % a[j] == 0 and dp[i] < dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                maxLenInd = i;
            }
        }
        
        vector<int> ans(maxLen);
        ans[0] = a[maxLenInd];
        
        while(hash[maxLenInd] != maxLenInd) {
            maxLenInd = hash[maxLenInd];
            ans[--maxLen] = a[maxLenInd];
        }
        return ans;
    }
};