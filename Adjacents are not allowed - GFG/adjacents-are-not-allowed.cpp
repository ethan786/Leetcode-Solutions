// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSum(int n, vector<vector<int>> mat)
    {
        //vector<int> dp(n,0);
        
        int a = max(mat[0][0],mat[1][0]);
        int b = max(max(mat[0][0],mat[0][1]),max(mat[1][0],mat[1][1]));
        if(n==1){
            return a;
        }
        for(int i=2;i<n;i++){
            int c = max(a + max(mat[0][i],mat[1][i]),b);
            a=b;
            b=c;
        }
        return b;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < N; j++)
                cin>>mat[i][j];
        }
        
        Solution ob;
        cout<<ob.maxSum(N, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends