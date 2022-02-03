// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPalindrome(string str, int low, int high) 
    { 
        while (low < high) 
        { 
            if (str[low] != str[high]) 
                return false; 
            low++; 
            high--; 
        } 
        return true; 
    }

     
    void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart,  
                       int start, int n, string str) 
    { 
        
        if (start >= n) 
        { 
            allPart.push_back(currPart); 
            return; 
        } 
      
        
        for (int i=start; i<n; i++) 
        { 
            
            if (isPalindrome(str, start, i)) 
            { 
                 
                currPart.push_back(str.substr(start, i-start+1)); 
      
                
                allPalPartUtil(allPart, currPart, i+1, n, str); 
                  
                
                currPart.pop_back(); 
            } 
        } 
    }

    vector<vector<string>> allPalindromicPerms(string S) {
        int n = S.length(); 
  
         
        vector<vector<string> > allPart; 
      
        
        vector<string> currPart;  
      
        allPalPartUtil(allPart, currPart, 0, n, S); 

        return allPart;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends