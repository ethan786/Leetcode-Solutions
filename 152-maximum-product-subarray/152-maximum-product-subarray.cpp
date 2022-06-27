class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int mx = a[0];
        int mi = a[0];
        int ans = mx;
        for(int i = 1; i < n ; i++) {
            int x = max({a[i], a[i] * mx, a[i] * mi});
            mi = min({a[i], a[i] * mx, a[i] * mi});
            mx = x;
            ans = max(mx,ans); 
        }
        return ans;
    }
};