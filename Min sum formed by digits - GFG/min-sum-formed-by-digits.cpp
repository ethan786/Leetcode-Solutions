// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int a[], int n)
    {
        if(n == 1) return a[0];
        long long int x = 0, y = 0, c = 1;
        sort(a, a + n);
        int i = n-1, j = n-2;
        while(1) {
            if(i >= 0) x += c * a[i];
            if(j >= 0) y += c * a[j];
            c *= 10;
            i -= 2; j-=2;
            if(i < 0 and j < 0) break;
        }
        return x+y;
    }
};
// 2 3 4 5 6 8
// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends