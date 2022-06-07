class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int n = a.size();
        vector<int> l(n), r(n);
        stack<int> s;
        
        for(int i = 0; i < n; i++) {
            while(!s.empty() and a[s.top()] >= a[i]) s.pop();
            l[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() and a[s.top()] >= a[i]) s.pop();
            r[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int left = l[i], right = r[i];
            if(left + 1 <= k and right-1 >= k) {
                ans = max(ans, a[i] * (right - left - 1));
            }
        }        
        return ans;
    }
};