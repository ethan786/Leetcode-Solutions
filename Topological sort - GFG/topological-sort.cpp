// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void topoSortdfs(int src, vector<bool> &vis, stack<int> & s, vector<int> adj[]) {
    	vis[src] = true;
    	for(auto &node : adj[src]) {
    		if(!vis[node]){
    			topoSortdfs(node,vis,s,adj);
    		}
    	}
    	s.push(src);
    }

	
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<bool> vis(n,false);
    	stack<int> s;
    
    	for(int i=0;i<n;i++){
    		if(!vis[i])
    			topoSortdfs(i,vis,s,adj);
	    }
	    vector<int> ans;
	    while(!s.empty()) {
	        ans.push_back(s.top());
	        s.pop();
	    }
    	return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends