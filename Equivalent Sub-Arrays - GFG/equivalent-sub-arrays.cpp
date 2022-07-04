// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int a[], int n)
    {
        // int ans = 0;
        int j = 0;
        set<int> s;
        for(int i = 0; i < n ; i++) {
           s.insert(a[i]); 
        }
        int dis = s.size();
        map<int,int> m;
        int ans = 0;
        for(int i = 0; i < n ; i++) {
            m[a[i]]++;
            while(m.size() == dis) {
                // cout<<i<<endl;
                ans += n - i;
                m[a[j]]--;
                if(m[a[j]] == 0) m.erase(a[j]);
                j++;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends