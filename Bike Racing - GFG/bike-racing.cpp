// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long buzzTime(long n, long m, long l, long h[], long a[])
    {
        #define int int64_t
        
        int mi = *min_element(a,a+n);
        int hi = l / mi, lo = 1;
        
        while(lo <= hi) {
            int mid = lo + (hi-lo) / 2;
            int speed = 0;
            for(int i = 0; i < n; i++) {
                int x = h[i] + mid * a[i];
                if(x >= l) {
                    speed += x;
                }
            }
            if(speed >= m) {
                hi = mid - 1;
            }else {
                lo = mid + 1;
            }
        }
        #undef int
        return lo;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends