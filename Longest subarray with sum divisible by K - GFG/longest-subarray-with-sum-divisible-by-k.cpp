// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k) {
	    map<int, int> dp;
	    dp[0] = -1;
	    
	    int cur = 0, ans = 0;
	    
	    for(int i = 0; i < n; i++) {
	        cur += arr[i];
	        cur = (cur % k + k) % k;
	        if(dp.find(cur) != dp.end()) {
	            int len = i - dp[cur];
	            ans = max(ans, len);
	        } else {
	            dp[cur] = i;
	        }
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends