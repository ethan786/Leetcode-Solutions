class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int n = a.size();
        if(n < m * k) return -1; // base case
        
        int lo = 0, hi = *max_element(begin(a), end(a));
        int ans = 1e9;
        
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int c = 0, bouq = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] <= mid) {
                    c++;
                }else {
                    c = 0;
                }
                if(k == c) {
                    bouq++;
                    c = 0;
                }
            }
            if(bouq >= m) {
                ans = min(ans,mid);
                hi = mid - 1;
            }else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};