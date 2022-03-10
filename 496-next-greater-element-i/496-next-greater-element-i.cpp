class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> m;
        stack<int> s;
        vector<int> ans;
        int n = b.size();
        
        for(int i=n-1;i>=0;i--){
            if(s.size() == 0){
                m[b[i]] = -1;
            }else if(s.size() > 0 and s.top() > b[i]){
                m[b[i]] = s.top();
            }else if(s.size() > 0 and s.top() <= b[i]){
                while(s.size() > 0 and s.top() <= b[i]){
                    s.pop();
                }
                m[b[i]] = (s.size() > 0) ?  s.top() : -1;
            }
            s.push(b[i]);
        }
        
        for(auto &i : a){
            i = m[i];
        }
        return a;
    }
};