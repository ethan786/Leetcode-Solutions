class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int t) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> pref(n+1,vector<int>(m+1,0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                pref[i][j] = a[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
        int ans = 0, curSum = 0;
        unordered_map<int,int> mp;
        for(int r1 = 1; r1 <= n; r1++) {
            for(int r2 = r1; r2 <= n; r2++) {
                mp.clear();
                mp[0] = 1;
                for(int c = 1; c <= m; c++) {
                    curSum = pref[r2][c] - pref[r1-1][c];
                    if(mp.find(curSum - t) != mp.end()) {
                        ans += mp[curSum - t];
                    }
                    mp[curSum]++;
                }
            }
        }
        return ans;
    }
};
   
    
    
    
    
    
    
    
    
    
    
    
    