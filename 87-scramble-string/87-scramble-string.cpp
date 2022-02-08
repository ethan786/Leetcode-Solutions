class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>>(n+1,vector<bool>(n+1)));
        
        //dp[i][j][l] represent s1[i.....i+l-1] is scrambled string of s2[j.....j+l-1] or not
        //s1="great" and s2="rgeat"
        //eg->dp[0][0][2] means s1[0-1]("gr") is scrambled string of s2[0-1]("rg") or not
        //l - length
        
        for(int l = 1; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){
                for(int j = 0; j + l - 1 < n; j++){
                    if(l == 1){
                        //if length of string is one then we can manually check 
                        //that are both character of string are equal or not
                        dp[i][j][l] = s1[i] == s2[j];
                    }else{
                        //partioning
                        for(int gap = 1; gap < l; gap++){
                            int endgap = l - gap;
                            //here two case
                            //i--- --------- 
                            //j--- ---------
                            
                            //i--- ---------   
                            //j--------- ---
                            dp[i][j][l] = dp[i][j][l] | (dp[i][j][gap] and dp[i+gap][j+gap][endgap]);
                            dp[i][j][l] = dp[i][j][l] | (dp[i][j+endgap][gap] and dp[i+gap][j][endgap]);
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
// great
// rgeat
// g reat
// r geat
// gr eat
// rg eat
// gre at

// grea t
// g r
// r g