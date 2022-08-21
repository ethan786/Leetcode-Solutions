class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() and (s.top() > 0 and a[i] < 0)) {
                int x = s.top();
                if(abs(x) > abs(a[i])) {
                    a[i] = x;
                    s.pop();
                }else if(abs(x) < abs(a[i])){
                    s.pop();
                }else {
                    a[i] = 0;
                    s.pop();
                }
            } 
            if(a[i] != 0) s.push(a[i]);
        }
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};