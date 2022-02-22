// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycleDfs(int i,vector<bool> &vis,vector<int> adj[],int par){
        vis[i] = true;
        for(auto it : adj[i]){
            if(vis[it]){
                if(it != par){
                    return true;
                }
            }else if(!vis[it]){
                if(cycleDfs(it,vis,adj,i)) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int n, vector<int> adj[]) {
        vector<bool> vis(n+1,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycleDfs(i,vis,adj,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends