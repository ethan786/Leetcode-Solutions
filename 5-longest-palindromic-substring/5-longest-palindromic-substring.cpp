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
    
    
        // string longestPalindrome(string s) {
        //     int n = s.size();
        //     int dp[n][n];
        //     int len = 0,start = 0;
        //     for( int gap = 0 ; gap < n ; gap++ ){
        //         for(int i = 0 , j = gap ; j < n ; i++ , j++){
        //             if(gap == 0){
        //                 dp[i][j] = true;
        //             }else if(gap == 1 and s[i] == s[j]){
        //                 dp[i][j] = true;
        //             }else if(s[i] == s[j] and dp[i+1][j-1] == true){
        //                 dp[i][j] = true;
        //             }else{
        //                 dp[i][j] = false;
        //             }
        //             //answer
        //             if(dp[i][j]){
        //                 start = i;
        //                 len = gap+1;
        //             }
        //         }
        //     }
        //     return s.substr(start,len);
        // }
    
    //Now comes the better approach 
    //instead of checking ends of substring and the 
    //depending on smallersubstring using dp
    //we can start from the centre and then spread out
    
    int expand(string s, int i, int j) {
        int ans = 0;
        while(i >= 0 and j < s.size()) {
            if(s[i] == s[j]) {
                if(i == j){
                    ans++;
                }else{
                    ans += 2;
                }
                i--;j++;
            }else{
                return ans;
            }
        }
        return ans;
    }
    
    string longestPalindrome(string s){
        int n = s.size();
        int len,mx = -1, st;
        for(int i = 0; i < n; i++) {
            int l1 = expand(s,i,i);
            int l2 = expand(s,i,i+1);
            len = max(l1,l2);
            if(len > mx) {
                mx = len;
                st = i - (len-1)/2;
            }
        }
        return s.substr(st,mx);
    }
    
    
    
    
    
    
    
    
    
};