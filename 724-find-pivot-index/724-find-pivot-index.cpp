class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int sum = 0;
        for(auto &i : a) {
            sum += i;
        }
        int ls = 0, rs = sum-a[0];
        if(ls == rs) return 0;
        
        for(int i = 1; i < a.size(); i++) {
            ls += a[i-1];
            rs -= a[i];
            if(ls == rs) return i;
        }
        return -1;
    }
};