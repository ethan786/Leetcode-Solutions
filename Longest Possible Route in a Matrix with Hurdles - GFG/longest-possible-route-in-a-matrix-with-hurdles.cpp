// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:


int solve(vector<vector<int>> arr,int r,int c,int i,int j,int xd,int yd){
       if(i<0 || i>=r || j<0 || j>= c || arr[i][j] == 0){
           return -INT_MAX/2;
       }
       
       if(i == xd && j == yd){
           return 0;
       }
       
       arr[i][j]=0;
       int p = solve(arr,r,c,i+1,j,xd,yd) + 1;
       int q = solve(arr,r,c,i,j+1,xd,yd) + 1;
       int t = solve(arr,r,c,i-1,j,xd,yd) + 1;
       int s = solve(arr,r,c,i,j-1,xd,yd) + 1;
       
       return max(p,max(q,max(t,s)));
   }
   
   int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
   {
       int r = matrix.size();
       int c = matrix[0].size();
       int temp = solve(matrix,r,c,xs,ys,xd,yd);
       
       if(temp < 0){
           return -1;
       }
       else{
           return temp;
       }
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends