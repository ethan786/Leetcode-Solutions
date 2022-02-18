class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1){
            return 5;
        }
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        //base case for n=2
        int x = 0;
        for(int i=0;i<5;i++){
            dp[1][i] = 5-i;
            x += dp[1][i];
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<5;j++){
                if(j == 0){
                    dp[i][j] = x;
                    x = dp[i][j];
                }else{
                    dp[i][j] = dp[i][j-1] - dp[i-1][j-1];
                    x += dp[i][j];
                }
            }
        }
        return dp[n][0];
    }
};
//5+4+3+2+1 = 15
//15+10+6+3+1 = 35(front)
//back -> 15*5 = 125
//middle ->15+14+13+12+11 = 
//4
//35+20+10+4+1 = 70
//70+35+15+5+1 = 126