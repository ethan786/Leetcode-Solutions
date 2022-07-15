class Solution {
public:
    int arrayNesting(vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int st = a[i], count = 0;
                do {
                    vis[st] = 1;
                    st = a[st];
                    count++;
                }while(a[i] != st);
                ans = max(ans,count);
            }
        }
        return ans;
    }
};