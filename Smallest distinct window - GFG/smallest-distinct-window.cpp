// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string s) {
        set<char> st;
        for(auto &i : s) st.insert(i);
        
        int x = st.size();
        
        if(x == s.size()) {
            return x;
        }
        
        int j = 0, ans = INT_MAX;
        unordered_map<char,int> m;
        
        for(int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            while(m.size() == x) {
                ans = min(ans, i-j+1);
                m[s[j]]--;
                if(m[s[j]] == 0) m.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends