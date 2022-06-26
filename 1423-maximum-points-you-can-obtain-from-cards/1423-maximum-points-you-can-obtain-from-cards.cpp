class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int sum = accumulate(a.begin(),a.end(),0);
        int cur_Sum = 0, n = a.size();
        
        for(int i = 0; i < n-k; i++) {
            cur_Sum += a[i];
        }
        int j = 0;
        int ans = sum - cur_Sum;
        for(int i = n-k; i < n; i++) {
            cur_Sum += a[i];
            cur_Sum -= a[j++];
            ans = max(ans, sum - cur_Sum);
        }
        return ans;
    }
};
