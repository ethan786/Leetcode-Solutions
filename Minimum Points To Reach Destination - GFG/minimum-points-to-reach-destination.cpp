// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	
	int minPoints(vector<vector<int>> p, int m, int n) 
	{ 
	    vector<vector<int>> dp(m,vector<int>(n,0));
	    //filling last row and colume
	    dp[m-1][n-1] = max(1,1-p[m-1][n-1]);
	    
	    for(int i = m-2;i>=0;i--){
	        dp[i][n-1] = max(1,dp[i+1][n-1] - p[i][n-1]);
	    }
	    for(int i = n-2;i>=0;i--){
	        dp[m-1][i] = max(1,dp[m-1][i+1] - p[m-1][i]);
	    }
	    
	    for(int i = m-2;i>=0;i--){
	        for(int j=n-2;j>=0;j--){
	            dp[i][j] = max(1,(min(dp[i][j+1],dp[i+1][j]) - p[i][j]));
	        }
	    }
	    
	    return dp[0][0];
	    

	  
	   
	} 
};


// { Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(a, m, n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends