// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    bool solve(int i, int a[], int n, vector<int> &dp) {
        if(i >= n-1) return true;
        if(a[i] == 0) return false;
        
        if(dp[i] != -1) return dp[i];
        
        bool ans = false;
        for(int j = 1; j <= a[i]; j++) {
            ans = ans | solve(i+j,a,n,dp);
            if(ans == true) return true;
        }
        return dp[i] = ans;
    }
  
    int canReach(int a[], int n) {
        vector<int> dp(n,-1);
        return solve(0,a,n,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends