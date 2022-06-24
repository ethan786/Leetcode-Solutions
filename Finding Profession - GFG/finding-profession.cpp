// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // char profession(int level, int pos){
        char profession(int level, int pos){
        // code here
        if (pos == 1) return 'e';
        
        int flips = 0;
        while (pos != 1) {
            long int order = 1;
            while (pos > order) {
                order *= 2;
            }
            
            pos = pos - (order/2);
            flips++;
        }
        
        return (flips % 2 == 0) ? 'e' : 'd';

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends