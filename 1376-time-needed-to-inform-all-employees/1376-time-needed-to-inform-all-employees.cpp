class Solution {
public:
    int numOfMinutes(int n, int h, vector<int>& a, vector<int>& t) {
        vector<int> adj[n];
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(a[i] == -1) {
                q.push(i);
                continue;
            }
            adj[a[i]].push_back(i);
        }
        vector<int> vis(n,0);
        vis[q.front()] = t[q.front()];
        int ans = t[q.front()];
        while(!q.empty()) {
            int m = q.size();
            int mx = INT_MIN;
            for(int x = 0; x < m; x++) {
                int node = q.front();
                q.pop();
                for(auto &i : adj[node]) {
                    if(!vis[i]) {
                        vis[i] = t[i] + vis[node];
                        q.push(i);
                    }
                }
            }
        }
        return *max_element(vis.begin(),vis.end());
    }
};