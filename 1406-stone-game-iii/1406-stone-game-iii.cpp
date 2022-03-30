class Solution {
public:
    int dp[50001];
    int solve(int i,vector<int>& a){
        if(i >= a.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        ans = max(ans,a[i] - solve(i+1,a));
        if(i+1 < a.size()){
            ans = max(ans,a[i] + a[i+1] - solve(i+2,a));
        }
        if(i+2 <a.size()){
            ans = max(ans,a[i] + a[i+1] + a[i+2] - solve(i+3,a));
        }
        return dp[i] = ans;
    }
    
    string stoneGameIII(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        int x = solve(0,a);
        //cout<<x;
        if(x > 0){
            return "Alice";
        }else if(x < 0){
            return "Bob";
        }else{
            return "Tie";
        }
    }
};