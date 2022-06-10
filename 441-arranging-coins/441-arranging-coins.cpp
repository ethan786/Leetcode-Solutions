class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 0, hi = n;
        while(lo <= hi) {
            long m = (lo + hi) / 2;
            long sum = (m *(m + 1)) / 2;
            if(sum == n) {
                return (int)m;
            }else if(sum > n) {
                hi = m - 1;
            }else {
                lo = lo + 1;
            }
        }
        return hi;
    }
};