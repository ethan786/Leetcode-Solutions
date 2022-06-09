class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() and a[s.top()] <= a[i]) {
                s.pop();
            }
            ans[i] = (s.empty()) ? -1 : a[s.top()];
            s.push(i);
        }
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() and a[s.top()] <= a[i]) {
                s.pop();
            }
            ans[i] = (s.empty()) ? -1 : a[s.top()];
            s.push(i);
        }
        return ans;
    }
};