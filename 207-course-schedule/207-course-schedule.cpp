class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> in(n,0);
        for(auto &i : a) {
            in[i[1]]++;
        }
        
        vector<int> adj[n];
        
        for(auto &i : a) {
            adj[i[0]].push_back(i[1]);
        }
        
        int c = 0;
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(in[i] == 0) {
                c++;
                q.emplace(i);
            }
        }
        vector<int> vis(n,0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto &i : adj[node]) {
                if(!vis[i]) {
                    in[i]--;
                    if(in[i] == 0) {
                        vis[i] = 1;
                        q.push(i);
                        c++;
                    }
                }
            }
        }
        
        return c == n;
        
    }
};