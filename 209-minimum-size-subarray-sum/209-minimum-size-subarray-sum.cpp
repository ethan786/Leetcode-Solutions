class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int sum = 0, n = a.size(), ans = INT_MAX;
        int j = 0;
        for(int i = 0 ; i < n; i++) {
            sum += a[i];
            if(sum >= t) {
                ans = min(ans, i-j+1);
                while(sum >= t) {
                    sum -= a[j];
                    j++;
                    if(sum >= t) {
                        ans = min(ans, i-j+1);
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};