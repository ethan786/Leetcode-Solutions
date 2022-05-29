// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool ans;
    
    void dfs(int i, int par, vector<int> &color, vector<int> adj[]) {
        color[i] = 1; //grey
        //cout<<i<<endl;
        for(auto it : adj[i]) {
            if(color[it] == 1) {
                ans = true;
            }
            if(color[it] == 0) {
                dfs(it,i,color,adj);
            }
        }
        color[i] = 2; // black
    }
    
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> color(n,0);
        ans = false;
        for(int i = 0; i < n; i++) {
            if(color[i] == 0) {
                dfs(i,-1,color,adj);
            }
            if(ans) return true;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends