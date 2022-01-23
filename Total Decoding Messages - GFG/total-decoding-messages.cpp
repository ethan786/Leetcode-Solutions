// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int m = 1e9+7;
	    
	     
		int CountWays(string s){
		    int n = s.size();
        vector<int> dp(n,0);
        if(s[0] == '0') return 0;
        dp[0]=1;
        for(int i=1;i<n;i++){
            int one_digit = (s[i]-'0');
            int two_digit = (s[i-1]-'0')*10 + (s[i]-'0');
            //cout<<one_digit<<" "<<two_digit;
            if(one_digit > 0) dp[i] = dp[i-1]%m;
            if(i>=2 and two_digit < 27 and two_digit >=10) dp[i] += dp[i-2]%m;
            if(i==1 and two_digit < 27 and two_digit >=10){
                 dp[i]+=1;
            }
        }
        return dp[n-1]%m;
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