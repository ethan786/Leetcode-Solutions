// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    
    long long solve(int s, int par, vector<int> adj[], int* c) {
        long long req = 0, child = 0;
        for(auto &i : adj[s]) {
            if(i != par) {
                child++;
                long long ch_req = solve(i,s,adj,c);
                if(ch_req == -1) return -1;
                req = max(req, ch_req);
            }
        }
        
        if(child * req + c[s-1] > 1e18) return -1;
        
        return child * req + c[s-1];
    }

    long long minimum_amount(vector<vector<int>> &a, int N, int s, int *c){
       vector<int> adj[N+1];
       for(int i = 0; i < a.size(); i++) {
           adj[a[i][0]].push_back(a[i][1]);
           adj[a[i][1]].push_back(a[i][0]);
       }
       long long ans = solve(s,-1,adj,c);
    //   if(ans > 1e18) return -1;
       return ans;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends