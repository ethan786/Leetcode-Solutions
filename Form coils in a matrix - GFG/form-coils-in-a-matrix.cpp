// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        
        // code here
        vector<vector<int>> coils(2);
        int nn = 16 * n * n, dir = 1, ind = 0;
        // Starting from middle
        coils[0].push_back(2 * n * (4 * n + 1));
        for(int i = 2; i < 4*n; i += 2){
            for(int j = 0; j < i; j++){
                coils[0].push_back(coils[0][ind++] - (4 * n * dir));
            }
            for(int j = 0; j < i; j++){
                coils[0].push_back(coils[0][ind++] + dir);
            }
            dir *= -1;
        }
        // Filling last layer
        for(int i = 0; i < 4*n  - 1; i++){
            coils[0].push_back(coils[0][ind++] + 4 * n);
        }
        // Both coils are dependent
        for(int i = 0; i < coils[0].size(); i++){
            coils[1].push_back(16 * n * n + 1 - coils[0][i]);
        }
        return coils;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends