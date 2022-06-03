// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long s, long long n, long long x, long long a[])
    {
        long long sum = s;
        vector<long long> v(n+1);
        v[0] = s;
        long long i = 1;
        for(i = 1; i <= n && sum <= x; i++) {
            v[i] = sum + a[i-1];
            sum += v[i];
        }
        
        for(; i >= 0; i--) {
            if(x >= v[i]) {
                x -= v[i];
            }
        }
        
        if(x == 0) {
            return 1;
        }
        
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends