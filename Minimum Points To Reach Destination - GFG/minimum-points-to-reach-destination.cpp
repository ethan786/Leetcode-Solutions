// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	
	int minPoints(vector<vector<int>> p, int m, int n) 
	{ 
	    
	    if(m==1 and n == 1){
	        return max(1,1-p[m-1][n-1]);
	    }
	    
	    if(n==1){
	        int ans = max(1,1-p[m-1][0]);
	        for(int i=m-2;i>=0;i--){
	            ans = max(1,ans-p[i][0]);
	        }
	        return ans;
	    }else if(m==1){
	        int ans = max(1,1-p[0][n-1]);
	        for(int i=n-2;i>=0;i--){
	            ans = max(1,ans-p[0][i]);
	        }
	        return ans; 
	    }
	    
      vector<int> dp(n,0);
      
      dp[n-1] = max(1,1-p[m-1][n-1]);

      
      for(int i = n-2;i>=0;i--){
          dp[i] = max(1,dp[i+1] - p[m-1][i]);
      }
      int prev = max(1,dp[n-1] - p[m-2][n-1]);
    //   for(int x=0;x<n;x++){
    //       cout<<dp[x]<<" ";
    //     }
    //     cout<<endl;
      for(int i = m-2;i>=0;i--){
        prev = max(1,dp[n-1] - p[i][n-1]);
         dp[n-1] = prev;
        //cout<<dp[n-1]<<" ";
          for(int j=n-2;j>=0;j--){
              dp[j] = max(1,(min(prev,dp[j]) - p[i][j]));
              prev= dp[j];
          }
      }     
      return dp[0];
      
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