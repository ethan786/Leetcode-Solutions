class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        priority_queue<int,vector<int>,greater<int>> p;
        int ans = 0;
        for(int i=0;i<c.size();i++) {
            if(c[i] - r[i] == 0) {
                ans++;
            }else{
                p.push(c[i] - r[i]);
            }
        }
        while(ar and !p.empty() and p.top() <= ar){
            int req = p.top();
            if(req <= ar) {
                ans++;
                ar -= req;
                p.pop();
            }
        }
        return ans;
    }
};