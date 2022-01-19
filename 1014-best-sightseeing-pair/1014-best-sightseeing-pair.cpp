class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i] = v[i]-i;
        }
        vector<int> mx(n);
        mx[n-1] = dp[n-1];
        int x = dp[n-1];
        for(int i=n-2;i>-1;i--){
            x = max(x,dp[i]);
            mx[i] = x;
        }
        x = 0;
        for(int i=0;i<n-1;i++){
            x = max(x,v[i]+i+mx[i+1]);
        }
        return x;
    }
};