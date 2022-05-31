// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    const int m = 1000003;
    
    int factorial(int n) {
        if(n == 1) return 1;
        return n * factorial(n-1);
    }
    
    int rank(string s){
        int f[256] = {0};
        for(auto &i : s) {
            f[i]++;
            if(f[i] > 1) return 0;
        }
        int n  = s.size();
        int fact = factorial(n);
        
        for(int i = 1; i < 256; i++) {
            f[i] += f[i-1];
        }
        
        int ans = 0;
        
        for(int i = 0; i < n ; i++) {
            fact /= (n-i);
            ans += f[s[i]-1] * fact;
            ans %= m;
            for(int j = s[i]; j < 256; ++j) {
                f[j]--;
            }
        }
        
        return (ans + 1)%m;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.rank(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends