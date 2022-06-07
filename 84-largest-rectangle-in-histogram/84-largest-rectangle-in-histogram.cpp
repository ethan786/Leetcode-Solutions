class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> l(n), r(n);
        stack<int> s;
        for(int i = 0; i < n; ++i) {
            while(!s.empty() and a[s.top()] >= a[i]) s.pop();
            l[i] = (s.empty()) ? i : i - s.top() - 1; 
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1; i >= 0; --i) {
            while(!s.empty() and a[s.top()] >= a[i]) s.pop();
            r[i] = (s.empty()) ? n-1-i : s.top()-i-1;
            s.push(i);
        }
        int ans = -1;
        for(int i = 0; i < n; ++i) {
            ans = max(ans,(l[i] + r[i] + 1) * a[i]);
        }
        return ans;
    }
};