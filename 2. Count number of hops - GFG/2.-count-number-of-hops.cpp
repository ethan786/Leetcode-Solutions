// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long m = 1000000007;
        
        vector<long long> v(n+1);
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        for(int i=3;i<=n;i++){
            v[i] = (v[i-1]%m + v[i-2]%m + v[i-3]%m)%m ;
        }
        return (long long)v[n]%m;
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends