// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
// Function to find element in sorted array

int leftIndex(int n, int a[], int x){
    int lo = 0, hi = n;
    int ans = -1;
    while(lo <= hi) {
        int m = lo + (hi - lo)/2;
        if(a[m] >= x) {
            ans = m;
            hi = m - 1;
        }else {
            lo = m + 1;
        }
    }
    return a[ans] != x ? -1 : ans;
}




// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    int elemntToSearch;
	    cin >> elemntToSearch;
	    
	    cout << leftIndex(sizeOfArray, arr, elemntToSearch) << endl;
	}
	
	return 0;
}  // } Driver Code Ends