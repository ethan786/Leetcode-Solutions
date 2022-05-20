// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string s1, string s2) {
        map<char,int> m;
        for(int i = 0;i<s1.size();i++) {
            m[s1[i]] = i;
        }
        int ans = 0;
        int curPos = 0;
        for(int i=0;i<s2.size();i++){
            char c = s2[i];
            int pos = m[c];
            ans += abs(pos - curPos);
            curPos = pos;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends