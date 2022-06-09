class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        
        int n = a.size(), m = a[0].size(), ans = 0;
        if(n == 0) return 0;
        vector<int> h(m),l(m,0),r(m,m);
        
        for(int i= 0 ; i < n; i++) {
            int cur_l = 0, cur_r = m;
            //height
            for(int j = 0; j < m; j++) {
                h[j] = (a[i][j] == '1') ? h[j] + 1 : 0; 
            }
            //left
            for(int j = 0; j < m; j++) {
                l[j] = (a[i][j] == '1') ? max(l[j], cur_l) : 0; 
                if(a[i][j] != '1') cur_l = j+1;
            }
            //right
            for(int j = m-1; j > -1; j--) {
                r[j] = (a[i][j] == '1') ? min(r[j], cur_r) : m; 
                if(a[i][j] != '1') cur_r = j;
            }
            //ans
            for(int j = 0; j < m; j++) {
                ans = max(ans, h[j] * (r[j] - l[j])); 
            }
        }
        return ans;
    }
};