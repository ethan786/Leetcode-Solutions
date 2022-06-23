// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	const int m = 1000000007;
	int TotalWays(int n) {
	    n += 3;
	    long long a = 0, b = 1;
	    for(int i = 2; i < n; i++) {
	        long long c = (a%m + b%m)%m;
	        a = b%m;
	        b = c%m;
	    }
	    return (int)((b)*1LL*(b) % m);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends