class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        
        if(n < 3) return 0;
        
        int l = a[0], r = a[n-1];
        int i = 0, j = n-1;
        int ans = 0;
        while(i <= j) {
            if(l < r) {
                if(a[i] > l) {
                    l = a[i];
                }else {
                    ans += l - a[i];
                    i++;
                }
            }else {
                if(a[j] > r) {
                    r = a[j];
                }else {
                    ans += r - a[j];
                    j--;
                }
            }
        }
        return ans;
    }
};