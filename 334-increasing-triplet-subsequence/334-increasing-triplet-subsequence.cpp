class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        vector<int> left(n,-1), right(n,n);
        for(int i = 0; i < n; i++) {
            while(!s.empty() and a[s.top()] >= a[i]) s.pop();
            left[i] = (s.empty() ? -1 : s.top());
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() and a[s.top()] <= a[i]) s.pop();
            right[i] = (s.empty() ? n : s.top());
            s.push(i);
        }
         for(int i = 1; i < n-1; i++) {
             if(left[i] >= 0 and right[i] <= n-1) return true;
        }
        return false;
    }
};