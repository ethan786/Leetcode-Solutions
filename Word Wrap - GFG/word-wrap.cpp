// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(int ind ,int n , vector<int>& nums , int k , vector<int>& dp){
        if(ind >= n )
        return 0;
        if(dp[ind] != -1)
        return dp[ind];
        int ans = INT_MAX;
        int sum = 0 ;
        for(int i = ind ; i < n ; i++){
            sum += nums[i];
            if(sum + (i - ind) <=k){
                int cost = 0;
                if(i != n - 1){
                    cost = pow(k - sum - i + ind , 2);
                }
                ans = min(ans ,cost + solve(i + 1, n , nums , k , dp));
              
            }
        }
        return dp[ind] = ans;
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size() ;
        vector<int>dp(n , -1);
        return solve(0 , n , nums , k , dp);
    }  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends