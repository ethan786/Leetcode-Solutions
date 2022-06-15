class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        #define int int64_t
        int n = a.size(), ans = 0;
        vector<int> l(n,-1), r(n,n);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() and a[s.top()] >= a[i]) s.pop();
            l[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() and a[s.top()] > a[i]) s.pop();
            r[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        int m = 1e9+7;
        for(int i= 0; i < n; i++) {
            int left = i - l[i];
            int right = r[i] - i;
            int x = (left * right) % m;
            int y = (a[i] * x) % m;
            ans += y;
            ans %= m;
        }
        #undef int
        return ans;
    }
};

