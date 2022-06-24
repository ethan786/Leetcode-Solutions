// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>a, int k){
        int n = a.size();
        vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));
    
        for(int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][a[0]] = true;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= k; j++) {
                // cout<<i<<" "<<j<<endl;
                bool notake = dp[i-1][j];
                bool take = false;
                if(a[i] <= j) take = dp[i-1][j-a[i]];
                dp[i][j] = take | notake;
            }
        }
        return dp[n-1][k];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends