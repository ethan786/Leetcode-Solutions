// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minDeletions(int nums[], int n) 
	{ 
	    vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            int ele = nums[i];
            auto lb = lower_bound(v.begin(),v.end(),ele);
            if(lb == v.end()){
                v.push_back(ele);
            }else{
                int index = lb - v.begin();
                v[index] = nums[i];
            }
        }
        
        return n - v.size();
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends