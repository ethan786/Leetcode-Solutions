class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if(n == 1) {
            return a[0];
        }else if(n == 2) {
            return max(a[0], a[1]);
        }
        // vector<int> dp(n+1,0);
        int d = a[0];
        int b = max(a[0],a[1]);

        for(int i = 2; i < n; i++) {
            int c = max(b, d + a[i]);
            d = b;
            b = c;
        }

        return b;
    }
};