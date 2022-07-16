class Solution {
public:
    int arrayNesting(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int st = a[i], c = 0;
            a[i] = INT_MAX;
            while(st != INT_MAX) {
                int p = st;
                st = a[st];
                // cout<<st<<endl;
                a[p] = INT_MAX;
                c++;
            }
            ans = max(ans,c);
        }
        return ans;
    }
};