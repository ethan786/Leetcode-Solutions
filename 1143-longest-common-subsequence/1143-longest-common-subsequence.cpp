class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<int> prev(m+1,0), cur(m+1,0);
        
        for(int i = 0; i <= m; i++) prev[i] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i-1] == b[j-1]) {
                    cur[j] = 1 + prev[j-1];
                }else {
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};