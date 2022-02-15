// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	vector<int> LIS(vector<int> a,int n){
	    vector<int> dp(n,1);
	    dp[0] = 1;
	    dp[1] = a[0] < a[1] ? 2 : 1;
	    for(int i=2;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(a[i] > a[j]){
	                dp[i] = max(dp[i],dp[j]+1);
	            }
	        }
	    }
	    return dp;
	}
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    if(nums.size() == 1 ||nums.size() == 2 ){
	        return nums.size();
	    }
	    vector<int> lis = LIS(nums,nums.size());
	    reverse(nums.begin(),nums.end());
	    vector<int> blis = LIS(nums,nums.size());
	    int mx = 0;
	    int n = nums.size();
	    for(int i=0;i<nums.size();i++){
	        mx = max(mx,lis[i] + blis[n-i-1] - 1);
	    }
	    return mx;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends