class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        if(a[0][0] == 1) return -1;
        if(a[0][0] == 0 and n == 1 and m == 1) return 1;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        
        auto isPossible = [&](int i, int j){
            if(i < 0 || j < 0 || i >= n || j >= m) return false;
            return true;
        };
        
        int dx[] = {0,0,1,-1,1,1,-1,-1};
        int dy[] = {1,-1,1,-1,0,-1,0,1};
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first.first;
            int j = p.first.second;
            int len = p.second;
            
            for(int x = 0; x < 8; x++) {
                int ci = i + dx[x];
                int cj = j + dy[x];
                if(isPossible(ci,cj) and a[ci][cj] == 0 and vis[ci][cj] == 0) {
                    q.push({{ci,cj},len+1});
                    vis[ci][cj] = 1;
                    if(ci == n-1 and cj == m-1) {
                        return len + 1;
                    }
                }
            }
            
        }
        return -1;
    }
};