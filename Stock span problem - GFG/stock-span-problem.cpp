// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
    stack<pair<int,int>> s;
       vector<int> a(n);
       a[0] = 1;
       s.push({price[0],0});
       for(int i=0;i<n;i++){
            while(s.size() > 0 and s.top().first <= price[i]){
                   s.pop();
               }
               if(s.size() == 0){
                   a[i] = i+1;
               }else{
                   a[i] = i - s.top().second;
               }
           s.push({price[i],i});
       }
       return a;
//     stack<int> s;
//   s.push(0);//pushing 0 in starting 
//   vector<int> v;
//   v.push_back(1);
//   for(int i=1;i<n;i++)
//   {
//       int cur = price[i];
//       while(!s.empty() and cur >= price[s.top()])
//       {
//           s.pop();
//       }
//       if(!s.empty())
//       {
//           int x =s.top();
//           v.push_back(i-x);
//       }
//       else
//       {
//           v.push_back(i+1);
//       }
//       s.push(i);
//   }
//   return v;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends