class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> a(n,vector<int>(m,0));
        
        if(n==1 and m == 1) {
            return mat[0][0]-'0';
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == '1') {
                    a[i][j] = j == 0 ? 1 : a[i][j-1] + 1;
                
                    int wd = a[i][j];
                    for(int k = i; k >= 0; k--) {
                        wd = min(wd,a[k][j]);
                        ans = max(ans, wd * (i-k+1));
                    }
                }
            }
        }
        return ans;
    }
};