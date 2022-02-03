// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> primeDivision(int N){
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= N; i++) {
            if (!isPrime[i]) 
                continue;
            if (i > N / i) 
                break;
            for (int j = i * i; j <= N; j += i) 
                isPrime[j] = false;
        }
        for(int i = 2; i <= N; ++i) {
            if(isPrime[i] && isPrime[N - i]) {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(N - i);
                return ans;
            }
        }
        vector<int> ans;
        return ans;
      // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends