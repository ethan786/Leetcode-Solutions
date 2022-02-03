// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


class Solution{
	public:
    	long long findNth(long long N)
    {
        long long base10num = N;
        long long base9num = 0;
        long long pos = 1;
        while( base10num>0 )
        {
            base9num += pos * (base10num%9);
            base10num /= 9;
            pos *= 10;
        }
       
       return base9num; 
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}

  // } Driver Code Ends