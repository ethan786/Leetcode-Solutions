class Solution {
public:
    
    int numSubarraysWithSum(vector<int>& a, int g) {
        int n = a.size(), ans = 0;
        map<int,int> m;
        int p = 0;
        m[0] = 1;
        for(int i = 0; i < n; i++) {
            p += a[i];
            // cout<<p<<" "<<g-p<<" "<<m[g-p]<<endl;
            ans += m[p-g];
            m[p]++;
        }
        return ans;
    }
};