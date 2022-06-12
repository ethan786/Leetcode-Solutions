// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	vector<vector<int>> dp;
	
	int solve(int i, string s, int sum) {
	    if(i == s.size()) return 1;
	    if(dp[i][sum] != -1) return dp[i][sum];
	    int curSum = 0, ans = 0;
	    for(int ind = i; ind < s.size(); ind++) {
	        curSum += s[ind] - '0';
	        if(curSum >= sum)
    	        ans += solve(ind+1,s,curSum);
	    }
	    return dp[i][sum] = ans;
	}
	
	int TotalCount(string s){
	    int n = s.size();
	    dp.resize(n,vector<int>(9*n,-1));
	    return solve(0,s,0);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends