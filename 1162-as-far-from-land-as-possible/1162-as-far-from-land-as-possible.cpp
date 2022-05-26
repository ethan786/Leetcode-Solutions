class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        queue<pair<int,int>> q;
        int n = a.size(), m = a[0].size(); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == 1) q.push({i,j});
            }
        }
        
        auto isPossible = [&](int x, int y){
          if(x >= 0 and y >= 0 and x < n and y < m) return true;
          return false;
        };
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        int ans = 0;
        while(!q.empty()) {
            int n = q.size();
            ans++;
            for(int x = 0; x < n; ++x) {
                auto p = q.front();
                q.pop();
                int i = p.first, j = p.second;
                for(int k = 0;k < 4; k++) {
                    int ci = i + dx[k];
                    int cj = j + dy[k];
                    if(isPossible(ci,cj) and a[ci][cj] == 0) {
                        q.push({ci,cj});
                        a[ci][cj] = 1;
                    }
                }
            }
        }
        ans = (ans == 1) ? -1 : ans - 1;
        return ans;
    }
};