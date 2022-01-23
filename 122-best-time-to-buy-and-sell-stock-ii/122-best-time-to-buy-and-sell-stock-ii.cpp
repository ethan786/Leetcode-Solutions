class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size()-1;
        //dp[i] max profit till ith day
        //two choice either to buy or not
        //if buy then have to sell on next day
        vector<int> dp(n+1,0);
        if(n==0){
            return 0;
        }
        dp[0] = (p[0] < p[1]) ? p[1]-p[0] : 0;
        
        //dp[1] = (p[0] < p[1]) ? p[1]-p[0] : 0;
        for(int i=1;i<n;i++){
            if(i+1 <= n and p[i+1] > p[i]){
                //cout<<p[i+1]-p[i]<<" i -> "<<i<<endl;
                dp[i] = dp[i-1] + (p[i+1]-p[i]); // buy and sell
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};