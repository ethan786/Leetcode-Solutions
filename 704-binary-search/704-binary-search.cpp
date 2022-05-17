class Solution {
public:
    int search(vector<int>& a, int t) {
        int l = 0, h = a.size()-1;
        while(l <= h){
            int m = l + (h - l) / 2;
            if(a[m] == t){
                return m;
            }else if(a[m] > t){
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return -1;
    }
};