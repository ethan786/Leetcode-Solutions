// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<string> ans;
    
    void solve(int i,vector<string>& d, string s, vector<string> possibleAns) {
        if(i == s.size()) {
            string x = "";
            for(auto &i : possibleAns) {
                x += i;
                x += " ";
            }
            x.pop_back();
            ans.push_back(x);
            return;
        }
        string x = "";
        for(int j = i; j < s.size(); j++) {
            x += s[j];
            if(binary_search(begin(d),end(d),x)) {
                possibleAns.push_back(x);
                solve(j+1,d,s,possibleAns);
                possibleAns.pop_back();
            }
        }
        
    }
    
    vector<string> wordBreak(int n, vector<string>& d, string s)
    {
        sort(begin(d),end(d));
        vector<string> x;
        solve(0,d,s,x);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends