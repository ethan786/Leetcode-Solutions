// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
int dp[1001][1001];
    int solve(vector<vector<int>>& matrix,int i,int j,int prev){
        if(i<0 || j<0 || i==matrix.size() || j==matrix[0].size() || prev>=matrix[i][j]){
            return 0;
        }
        if(dp[i][j]!= -1) return dp[i][j];
        int curr=matrix[i][j];
        return dp[i][j] = max({solve(matrix,i+1,j,curr),solve(matrix,i-1,j,curr),solve(matrix,i,j+1,curr),solve(matrix,i,j-1,curr)})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int ans = INT_MIN;
        for(int i=0;i<matrix.size();i++ ){
            for(int j=0;j<matrix[0].size();j++){
                int temp = solve(matrix,i,j,0);
                    ans = max(temp,ans);
            }
        }
        return ans;
    }
};
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends