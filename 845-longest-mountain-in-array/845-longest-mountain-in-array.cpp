class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();
        vector<int> up(n,0), down(n,0);
        for(int i = n-2; i >= 0; i--) {
            if(a[i] > a[i+1]) down[i] = 1 + down[i+1];
        }
        int ans = 0;
        for(int i = 0; i < n ; i++) {
            if(i > 0 and a[i] > a[i-1]) up[i] = 1 + up[i-1];
            if(up[i] and down[i]) ans = max(ans, up[i] + down[i] + 1);
        }
        return ans;
    }
};