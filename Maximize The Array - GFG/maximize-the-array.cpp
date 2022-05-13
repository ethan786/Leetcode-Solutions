// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n)
{

   vector<int> ans;
   map<int, pair<int, int>, greater<int>> m1;
   map<int, pair<int, int>, greater<int>> m2;
   for (int i = 0; i < n; i++)
   {
       if (m2.count(arr2[i]) == 0)
       {
           m2[arr2[i]].first = 2;
           m2[arr2[i]].second = i;
       }
   }
   for (int i = 0; i < n; i++)
   {
       if (m1.count(arr1[i]) == 0){
       m1[arr1[i]].first = 1;
       m1[arr1[i]].second = i;}
   }
   map<int, pair<int, int>, greater<int>> mf;
   for (auto i : m1)
   {
       mf[i.first] = i.second;
   }
   for (auto i : m2)
   {

       mf[i.first] = i.second;
   }
   // for (auto i :mf)
   // {
   //     cout<<"value is "<<i.first<<" array is "<<i.second.first<<" index is "<<i.second.second<<endl;
   // }
   map<int, pair<int, int>, greater<int>> m;
   int k=0;
   for (auto it = mf.begin();it!=mf.end();it++)
   {
       if(k==n)
       {
           break;
       }
       m[it->first] = it->second;
       k++;
   }
 
   auto it1 = m.begin();
   map<int, int> f1;
   map<int, int> f2;
   for (int i = 0; i < n; i++)
   {
       if (it1->second.first == 2)
       {
           f2[it1->second.second] = it1->first;
          
       }
       it1++;
   }
   auto it2 = m.begin();
   for (int i = 0; i < n; i++)
   {
       if (it2->second.first == 1)
       {
           f1[it2->second.second] = it2->first;
       }
       it2++;
   }
   for (auto i : f2)
   {
       ans.push_back(i.second);
   }
   for (auto i : f1)
   {
       ans.push_back(i.second);
   }

   return ans;
}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends