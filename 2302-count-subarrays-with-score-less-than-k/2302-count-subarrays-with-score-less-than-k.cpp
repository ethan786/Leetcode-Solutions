class Solution {
public:
    long long countSubarrays(vector<int>& a, long long k) {
        long long ans = 0;
        int i = 0, j = 0;
        long long sum = 0;
        while(i < a.size()) {
            sum += a[i];
            while(sum * (i-j+1) >= k) {
                sum -= a[j];
                j++;
            }
            ans += (i - j + 1);
            i++;
        }
        return ans;
    }
};