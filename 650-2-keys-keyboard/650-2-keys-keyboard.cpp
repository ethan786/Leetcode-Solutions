class Solution {
public:
    
    int findDivisor(int a){
        for(int i=2;i<=sqrt(a);i++){
            if(a%i==0){
                return a/i;
            }
        }
        return -1;
    }
    
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        vector<int> dp(n+1,0);
        dp[1]=0;
        for(int i=2;i<n+1;i++){
            int x = findDivisor(i);
            //cout<<x<<" ";
            if(x==-1){
                dp[i] = i;
            }else{
            dp[i] = dp[x] + i/x;
            }
        }
        return dp[n];
    }
};