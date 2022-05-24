// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        vector<int> dis(n,INT_MAX);
        dis[src] = 0;
        set<pair<int, int>> s;
		s.insert({0,src});

		while(!s.empty()) {
			
			auto node = *s.begin();
			s.erase(s.begin());
			
			int parent = node.second;
			int parentDis = node.first;
			
			for(auto &i : adj[parent]) {
				int child = i[0];
				int egdeDis = i[1];

				if(parentDis + egdeDis < dis[child]) {

					//update if already present 
					auto f = s.find({dis[child], child});

					if(f != s.end()) {
						s.erase(f);
					}

					dis[child] = parentDis + egdeDis;
					s.insert({dis[child], child});
				}
			} 
		}
		return dis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends