// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int m = 1e9+7;
	    int solve(int i,string &s,vector<int> &dp){
	        if(i==s.size()){
	            return 1;
	        }
	        long long op1 = 0;
	        
	        if(dp[i] !=-1) return dp[i]%m;
	       
	        if(s[i] != '0'){
	         op1 = solve(i+1,s,dp)%m;
	        }
	        if(i < s.size()-1 and (s[i]-'0')*10 + (s[i+1]-'0') <=26 and (s[i]-'0') > 0){
	        op1 += solve(i+2,s,dp)%m;
	        }
	        return dp[i] = op1%m;
	    }
	     
		int CountWays(string str){
		    if(str[0] == '0') return 0;
		    vector<int> dp(str.size(),-1);
		    return solve(0,str,dp);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends