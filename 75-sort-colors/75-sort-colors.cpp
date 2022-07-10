class Solution {
public:
    void sortColors(vector<int>& a) {
        // 0 0 2 1 1 2
        // i         k
        // j
        // i - > 0
        // j - > 1
        // k - > 2
        int n = a.size();
        int i = 0, j = 0, k = n-1;
        
        while(j <= k) // =
        {
            if(a[j] == 0) {
                swap(a[i++],a[j++]);
            }else if(a[j] == 1) {
                j++;
            }else {
                swap(a[j],a[k--]);
            }
        }
        
    }
};