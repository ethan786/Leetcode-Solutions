// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums[])
    {
       vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            int ele = nums[i];
            auto lb = lower_bound(v.begin(),v.end(),ele);
            if(lb == v.end()){
                v.push_back(ele);
            }else{
                int index = lb - v.begin();
                v[index] = nums[i];
            }
        }
        
        return v.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends