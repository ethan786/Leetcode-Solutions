class Solution {
public:
    long long subArrayRanges(vector<int>& a) {
        long long ans = 0, n = a.size();
        for(int i = 0; i < n; i++) {
            int mi = a[i], mx = a[i];
            for(int j = i + 1; j < n ; j++) {
                mi = min(mi,a[j]);
                mx = max(mx,a[j]);
                ans += mx - mi;
            }
        }
        return ans;
    }
};