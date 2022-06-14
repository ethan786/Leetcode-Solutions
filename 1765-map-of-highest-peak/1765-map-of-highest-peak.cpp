class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        auto is = [&](int i, int j) {
            if(i < 0 || j < 0 || i >= n || j >= m || ans[i][j] != -1) return false;
            return true;
        };
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int i = node.first;
            int j = node.second;
            for(int x = 0; x < 4; x++) {
                int ci = i + dx[x], cj = j + dy[x];
                if(is(ci,cj)) {
                    q.push({ci,cj});
                    ans[ci][cj] = 1 + ans[i][j];
                }
            }
        }
        
        
        
        return ans;
    }
};