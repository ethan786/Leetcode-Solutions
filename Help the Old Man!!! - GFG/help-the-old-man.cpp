// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int cnt = 0, a, b;
    void TOH(int N, int n, int from, int to, int aux)
    {
        if(N == 0 || cnt >= n)
            return;
        TOH(N-1, n, from, aux, to);
        cnt += 1;
        if(cnt == n){
            a = from;
            b = to;
            return;
        }
        TOH(N-1, n, aux, to, from);
    }
    vector<int> shiftPile(int N, int n){
    	a = 0, b = 0;
        TOH(N, n, 1, 3, 2);
        return {a, b};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends