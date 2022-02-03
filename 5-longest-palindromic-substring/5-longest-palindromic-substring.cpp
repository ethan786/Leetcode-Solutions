class Solution {
public:
    
//     bool isPalindrome(string &x){
//         int n = x.size();
//         if(n==1) return true;
//         int i = 0,j = n-1;
//         while(i<=j){
//             if(x[i] != x[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
    
//     string longestPalindrome(string s) {
//         int n = s.size();
//         //brute-force
//         int best_s = 0;
//         int best_e = 0;
//         int mx = -1;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 string substring = s.substr(i,j-i+1);
//                 if(isPalindrome(substring)){
//                     int newLength = j-i+1;
//                     if(newLength > mx){
//                         best_s = i;
//                         best_e = j;
//                         mx = newLength;
//                     }
//                 }
//             }
//         }
        
//         return s.substr(best_s,best_e-best_s+1);
        
//     }
    
    
        string longestPalindrome(string s) {
            int n = s.size();
            int dp[n][n];
            int len = 0,start = 0;
            for( int gap = 0 ; gap < n ; gap++ ){
                for(int i = 0 , j = gap ; j < n ; i++ , j++){
                    if(gap == 0){
                        dp[i][j] = true;
                    }else if(gap == 1 and s[i] == s[j]){
                        dp[i][j] = true;
                    }else if(s[i] == s[j] and dp[i+1][j-1] == true){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                    //answer
                    if(dp[i][j]){
                        start = i;
                        len = gap+1;
                    }
                }
            }
            return s.substr(start,len);
        }
    
    
    
    
    
    
    
    
    
    
    
    
    
};