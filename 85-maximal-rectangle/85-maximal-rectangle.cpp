class Solution {
public:
    
    int MAH(vector<int> &a){
        int n = a.size();
        vector<int> l(n),r(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
                while(!s.empty() and a[s.top()] >= a[i]){
                    s.pop();
                }
                if(s.size() == 0){
                    l[i] = n - i;
                }else{
                    l[i] = s.top() - i;
                }
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        r[0] = 1;
        s.push(0);
        for(int i=1;i<n;i++){
                while(!s.empty() and a[s.top()] >= a[i]){
                    s.pop();
                }
                if(s.size() == 0){
                    r[i] = i + 1;
                }else{
                    r[i] = i-s.top();
                }
            s.push(i);
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            ans = max(ans,a[i] * (l[i]+r[i]-1));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<int> o(m);
        for(int i=0;i<m;i++){
            o[i] = v[0][i] - '0';
        }
        int ans = MAH(o);
        
        for(int i=1;i<n;i++){
            for(int j = 0;j<m;j++){
                if(v[i][j] == '0'){
                    o[j] = 0;
                }else{
                    o[j]++;
                }
            }
            ans = max(ans,MAH(o));
        }
        return ans;
    }
};