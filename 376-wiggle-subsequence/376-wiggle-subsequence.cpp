class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int x = a.size();
        int p = 0, n = 0;
        for(int i = 0; i < x-1; i++) {
            int dif = a[i+1] - a[i];
            if(dif > 0) {
                p = n + 1;
            }else if(dif < 0){
                n = p + 1;
            }
        }
        return max(p,n)+1;
    }
};