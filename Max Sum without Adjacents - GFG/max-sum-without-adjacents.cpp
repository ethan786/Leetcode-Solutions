// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>
class Solution{
public:	

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int a = arr[0];
	    int b = max(arr[0],arr[1]);
	    if(n==1){
	        return a;
	    }
	    for(int i=2;i<n;i++){
	        int c = max(a+arr[i],b);
	        a=b;
	        b=c;
	    }
	    return b;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends