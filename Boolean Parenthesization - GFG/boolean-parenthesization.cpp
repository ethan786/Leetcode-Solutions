// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[201][201][2];
    
    int solve(string &s,int i,int j,bool isTrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue){
                return s[i] == 'T';
            }else{
                return s[i] == 'F';
            }
        }
    
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int ans = 0;
        for(int k=i+1;k<j;k=k+2){
            int lt,lf,rt,rf;
            // int lt = solve(s,i,k-1,true); // left side humko true chahiye
            // int lf = solve(s,i,k-1,false); // left side humko false chahiye
            // int rt = solve(s,k+1,j,true); // right side humko true chahiye
            // int rf = solve(s,k+1,j,false); // right side humko false chahiye
            if(dp[i][k-1][true]!=-1){
                lt = dp[i][k-1][true];
            }else{
                lt = solve(s,i,k-1,true);
            }
            if(dp[i][k-1][false]!=-1){
                lf = dp[i][k-1][false];
            }else{
                lf = solve(s,i,k-1,false);
            }
            if(dp[k+1][j][true]!=-1){
                rt = dp[k+1][j][true];
            }else{
                rt = solve(s,k+1,j,true);
            }
            if(dp[k+1][j][false]!=-1){
                rf = dp[k+1][j][false];
            }else{
                rf = solve(s,k+1,j,false);
            }
            
            if(s[k] == '&'){
                if(isTrue == true){
                    ans = ans + lt*rt; 
                }else{
                    ans = ans + lf*rt + lf*rf + lt*rf;
                }
            }else if(s[k] == '|'){
                if(isTrue == true){
                    ans = ans + lt*rt + lf*rt + lt*rf; 
                }else{
                    ans = ans +   lf*rf ;
                }
            }else{
                if(isTrue == true){
                    ans = ans + lf*rt + lt*rf; 
                }else{
                    ans = ans + lt*rt + lf*rf;
                }
            }
            dp[i][j][isTrue] = ans%1003;
        }
        return ans%1003;
    }
 
    int countWays(int N, string S){
        memset(dp,-1,sizeof(dp));
        return solve(S,0,N-1,true);
    }
};



















// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends