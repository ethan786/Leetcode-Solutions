class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size(), ans = INT_MIN, cur = 0;
        for(int i = 0; i < n; i++) {
            cur += a[i];
            ans = max(cur, ans);
            if(cur < 0) {
                cur = 0;
            }
        }
        return ans;
    }
};