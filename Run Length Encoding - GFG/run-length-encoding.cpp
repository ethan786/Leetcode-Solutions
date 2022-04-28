// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
    string ans = "";
    int n = s.size(), co = 0;
    char c = s[0];
    for(int i=0;i<n;i++){
        //cout<<s[i]<<" "<<co<<" "<<c<<endl;
        if(c == s[i]){
            co++;
        }else{
            ans += c;
            ans += to_string(co);
            co = 1; c = s[i];
        }
    }
    ans += c;
    ans += to_string(co);
    return ans;
}     
 
