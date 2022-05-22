class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& a) {
        vector<bool> vis(a.size(), false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int c = 0;
        while(!q.empty()) {
            int node = q.front();
            c++;
            q.pop();
            for(auto &i : a[node]) {
                if(!vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        //cout<<c;
        return c == a.size();
    }
};