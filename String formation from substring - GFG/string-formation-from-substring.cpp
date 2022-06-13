// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
{
    string check="";
    int i=0;
    int l;
    int loop;
    string tr="";
    int sl =s.length();
    if(sl==1)return 0;
    while(i<sl/2){
        check+=s[i];
        l=check.length();
        loop=sl/l;
        while(loop){
            tr+=check;
            loop--;
        }
        if(tr==s)return 1;
        else {
            tr="";
            i++;
        }
    }
    return 0;
}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends