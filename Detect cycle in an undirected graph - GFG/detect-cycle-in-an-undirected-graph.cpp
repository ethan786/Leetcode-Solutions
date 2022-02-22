// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool cycleBfs(int i,vector<bool> &vis,vector<int> adj[]){
    vis[i] = true;
    queue<pair<int,int>> q;
    q.push({i,-1});
    while(!q.empty()){
        auto p = q.front();
        int node = p.first;
        int prev = p.second;
        q.pop();
        for(auto &it : adj[node]){
            if(vis[it] == true and prev != it ){
                return true;
            }else if(!vis[it]){
                vis[it] = true;
                q.push({it,node});
            }
        }
    }
    return false;
  }
    
    bool isCycle(int n, vector<int> adj[]) {
        vector<bool> vis(n+1,false);
        for(int i=0;i<n;i++){
        if(!vis[i]){
            if(cycleBfs(i,vis,adj)){
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