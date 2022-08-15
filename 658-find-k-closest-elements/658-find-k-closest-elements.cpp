class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int ind = lower_bound(a.begin(), a.end(), x) - a.begin();
        int i = ind-1, n = a.size();
        int j = ind;
        int l = 0;
        vector<int> ans(k);
        while(l != k) {
            int left = (i >= 0) ? abs(a[i] - x) : INT_MAX;
            int right = (j < n) ? abs(a[j] - x) : INT_MAX;
            if(left > right) {
                // cout<<l<<" "<<a[j]<<endl;
                ans[l++] = a[j++];
            }else {
                // cout<<l<<" "<<a[i]<<endl;
                ans[l++] = a[i--];
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};