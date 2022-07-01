// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    

 long long int arrangeTiles(int N){
       long long int a,b,c,d,e;
       a=b=c=1,d=2;
       for(int i=5;i<=N;i++){
           e = a + d;
           a=b,b=c,c=d,d=e;
       }
       if(N==0) return 0;
       if(N<4) return 1;
       return d;
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
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends