class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        //dp vector
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = a[i][j];
                }else{
                    // Calculate number of
                    // square submatrices
                    // ending at (i, j)
                    dp[i][j] = (a[i][j] == 1) ? 1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]}) : 0;
                }
            }
        }
        int sum = 0;
        //calculate number of square submatrices have all ones
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                sum += dp[i][j];
            }
        }
        return sum;
    }
};
