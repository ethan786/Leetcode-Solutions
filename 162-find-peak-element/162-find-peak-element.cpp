class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1;
        while(l < r){
            int m = (l + r)/2;
            if(a[m] > a[m+1]){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};