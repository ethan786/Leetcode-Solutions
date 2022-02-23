// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool ans;
    void dfs(int i,int par,vector<int> adj[],vector<int> &color){
        color[i] = 1;//grey
        for(auto it : adj[i]){
            if(color[it] == 1){
                ans = true;
            }
            if(color[it] == 0){ //white
                dfs(it,i,adj,color);
            }
        }
        color[i] = 2;//black
        //return false;
    }
    
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> color(n,0);
        ans = false;
        for(int i=0;i<n;i++){
            if(color[i] == 0){
                dfs(i,-1,adj,color);
            }
            if(ans){
                return true;
            }
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