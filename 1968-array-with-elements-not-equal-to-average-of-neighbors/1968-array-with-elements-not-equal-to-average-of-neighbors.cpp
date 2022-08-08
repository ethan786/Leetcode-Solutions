class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size();
        for(int i = 1; i < n-1; i++) {
            int avg = (a[i-1] + a[i+1]);
            if(2 * a[i] == avg) {
                swap(a[i], a[i+1]);
            }
        }
        for(int i = n-2; i > 0; i--) {
            int avg = (a[i-1] + a[i+1]);
            if(2 * a[i] == avg) {
                swap(a[i], a[i+1]);
            }
        }
        return a;
    }
};

