// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:


     void solve(int i,string &temp,string &s,vector<string> &ans){
        
        if(temp.size() > 1 && temp.substr(temp.size()-2) == "  "){
            return;
        }
        
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }    
        
        if(!temp.empty()){
            temp += " ";
            solve(i,temp,s,ans);
            temp.pop_back();    
        }

        temp += s[i];
        solve(i+1,temp,s,ans);
        temp.pop_back();
    }
    
    vector<string> permutation(string s){
        vector<string> ans;
        string x;
        solve(0,x,s,ans);
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends