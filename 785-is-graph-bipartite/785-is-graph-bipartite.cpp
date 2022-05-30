class Solution {
public:
    bool isBipartite(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> color(n,0);
        
        for(int i = 0; i < n; ++i) {
            if(color[i] == 0) {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for(auto &nbr : a[node]) {
                        if(color[nbr] == 0) {
                            color[nbr] = 3 - color[node];
                            q.push(nbr);
                        }else if(color[nbr] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};