class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& a) {
        vector<int> adj[n];
        map<pair<int,int>,int> m;
        for(auto &i : a) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            m[{i[0],i[1]}]++;
        }
        
        int ans = 0;
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto &i : adj[node]) {
                if(!vis[i]) {
                    if(m.find({i,node}) == m.end()) {
                        // cout<<i<<" "<<node<<" "<<m[i]<<endl;
                        ans++;
                    }
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        
        return ans;    
            
    }
};