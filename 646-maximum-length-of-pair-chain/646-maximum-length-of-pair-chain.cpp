class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[&](vector<int>& a,vector<int>& b){
        return a[0] < b[0];
        });
        
        int n = p.size();
        vector<int> dp(n,1);
        int ans = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
            if(p[j][1] < p[i][0]){
                dp[i] = max(dp[i],dp[j]+1);
            }
            }
        }
        for(int x:dp){
            ans = max(ans,x);
        }
        return ans;
    }
};