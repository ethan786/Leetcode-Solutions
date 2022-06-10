class Solution {
public:
    bool isPerfectSquare(int n) {
        int l = 1, r = n;
        while(l <= r) {
            long m = l + (r-l)/2;
            if(1ll*m*m == n) {
                return m;
            }else if(m*m < n) {
                l = m + 1;
            }else {
                r = m - 1;
            }
        }
        return 0;
    }
};