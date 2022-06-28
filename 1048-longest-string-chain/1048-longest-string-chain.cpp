class Solution {
public:
    bool check(string &a, string &b) {
        int i = 0, j = 0;
        if(b.size() + 1 != a.size()) return false;

        while(i < a.size()) {
            if(a[i] == b[j]) {
                i++;j++;
            }else {
                i++;
            }
        }
        return i == a.size() and j == b.size();
    }

    int longestStrChain(vector<string> &a)
    {
        int n = a.size(), ans = 1;

        sort(a.begin(), a.end(), [&](string &x, string &y){
            return x.size() < y.size();
        });
        vector<int> dp(n,1);
        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(check(a[i],a[j]) and dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                } 
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};