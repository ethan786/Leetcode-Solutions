class Solution {
public:
    int c(vector<int>& a, int g) {
        int sum = 0;
        int ans = 0;
        int i = 0, j = 0;
        while(i < a.size()) {
            sum += a[i];
            while(sum >= g and j <= i) {
                sum -= a[j];
                j++;
            }
            ans += (i - j + 1);
            i++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& a, int g) {
        return c(a,g+1) - c(a,g);
    }
};