class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n == 1){
            return 0;
        }
        if(n == 2){
            return (a[0] > a[1] ? 0 : 1);
        }
        for(int i = 0;i<n-1;i++){
            if(i == 0 and a[0] > a[1]){
                return i;
            }
            if(i != 0 and a[i] > a[i-1] and a[i] > a[i+1]){
                return i;
            }
        }
        return (a[n-1] > a[n-2]) ? n-1 : -1;
    }
};