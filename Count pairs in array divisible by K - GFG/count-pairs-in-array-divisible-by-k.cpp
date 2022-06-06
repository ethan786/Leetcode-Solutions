// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int a[], int n, int k)
    {
        unordered_map<int,int> m;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int x = a[i]%k;
            int y = k - x;
            if(x == 0) {
                ans += m[0];
            }else {
                ans += m[y];
            }
            m[x]++;
        }
        return ans;
    }
};

// 2 2 1 7 5 3
// a   f
// 2 - 2
// 1 - 2
// 3 - 2



// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends