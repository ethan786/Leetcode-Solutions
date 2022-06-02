// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool solve(int ind, int k, int m, vector<int>& a, vector<int>& dp){
        bool flag = false;
        if(ind < 0){
            return true;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        for(int i = ind - k + 1;( i >= 0 && a[ind] - a[i] <= m); i--){
            flag |= solve(i - 1, k, m, a, dp);
            if(flag == true){
                break;
            }
        } 
        dp[ind] = flag;
        return flag;
    }
    bool partitionArray(int n, int k, int m, vector<int> &a){
        sort(a.begin(), a.end());
        vector<int> dp(n, -1);
        solve(n - 1, k, m, a, dp);
        return dp[n - 1];
    }
     // 1 2 3 8 9
     //         9 ,8 ,3 (8-3) > m
     // 9 , 8 
     // 3, 2
     // 3, 2, 1
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends