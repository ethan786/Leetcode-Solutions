// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
     int transform (string s1, string s2)
   {
       //code here.
      int n=s1.size();
      if(s1.size()!=s2.size()) return -1;
   unordered_map<char,int>m1;
   unordered_map<char,int>m2;
   for(int i=0;i<n;i++){
       m1[s1[i]]++;
       m2[s2[i]]++;
   }
   if(m1!=m2) return -1;
      int i=n-1,j=n-1,cnt=0;
      while(i>=0 and j>=0){
          if(s1[i]==s2[j]) i--,j--;
          else cnt++,i--;
      }
    
      return cnt;
   }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends