class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int n = a.size();
        int lo = 0, hi = n-1;
        int fs = -1;
        while(lo <= hi) {
            int m = lo + (hi - lo) / 2;
            if(a[m] == t) {
                fs = m;
                hi = m - 1;
            }else if(a[m] < t) {
                lo = m + 1;
            }else {
                hi = m - 1;
            }
        }
        lo = 0;
        hi = n-1;
        int ls = -1;
        
        while(lo <= hi) {
            int m = lo + (hi - lo) / 2;
            if(a[m] == t) {
                ls = m;
                lo = m + 1;
            }else if(a[m] < t) {
                lo = m + 1;
            }else {
                hi = m - 1;
            }
        }
        
        return {fs, ls};
    }
};