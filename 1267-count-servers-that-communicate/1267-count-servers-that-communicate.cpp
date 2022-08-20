class Solution {
public:
    int countServers(vector<vector<int>>& a) {
        unordered_map<int,int> row, col;
        int n = a.size(), m = a[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1 and (row[i] > 1 || col[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};