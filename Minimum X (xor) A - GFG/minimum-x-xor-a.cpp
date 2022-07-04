// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int count(int n) {
        int c = 0;
        while (n) {
            n &= (n - 1);
            c++;
        }
        return c;
    }
    
    int minVal(int a, int b) {
        int cb = count(b);
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            if((a & (1<<i)) and cb) {
                ans += (1<<i);
                cb--;
            }
        }
        
        for(int i = 0; i < 32 and cb > 0; i++) {
            if(!(a & (1<<i))) {
                ans += (1 << i);
                cb--;
            } 
        }
        return ans;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends